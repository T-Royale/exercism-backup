const std = @import("std");
const mem = std.mem;

pub fn factors(allocator: mem.Allocator, value: u64) mem.Allocator.Error![]u64 {
    var result = try std.ArrayList(u64).initCapacity(allocator, 16);
    errdefer result.deinit(allocator);

    var n = value;
    var divisor: u64 = 2;

    while (divisor <= n / divisor) {
        while (n % divisor == 0) {
            try result.append(allocator, divisor);
            n /= divisor;
        }
        divisor += if (divisor == 2) 1 else 2;
    }

    if (n > 1) {
        try result.append(allocator, n);
    }

    return try result.toOwnedSlice(allocator);
}
