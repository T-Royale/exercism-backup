const std = @import("std");

const mem = std.mem;

pub fn sum(allocator: mem.Allocator, factors: []const u32, limit: u32) !u64 {
    var result: u64 = 0;
    var pos: usize = 0;

    var total_size: usize = 0;
    for (factors) |factor| {
        if (factor == 0) continue;
        total_size += (limit - 1) / factor;
    }

    var arr = try allocator.alloc(u32, total_size);
    defer allocator.free(arr);

    // Get all points
    for (factors) |factor| {
        var i = factor;
        while (i < limit and pos < arr.len) : (i += factor) {
            arr[pos] = i;
            pos += 1;
        }
    }

    // Sort points
    std.sort.pdq(u32, arr[0..pos], {}, std.sort.asc(u32));

    // Remove dupes
    if (pos == 0) return 0;
    for (1..pos) |i| {
        if (arr[i] == arr[i - 1]) {
            arr[i - 1] = 0;
        }
    }

    // Sum points
    for (arr[0..pos]) |points| {
        result += points;
    }
    return result;
}

