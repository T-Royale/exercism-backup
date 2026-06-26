const std = @import("std");
const mem = std.mem;
const fmt = std.fmt;

pub fn recite(allocator: mem.Allocator, words: []const []const u8) mem.Allocator.Error![][]u8 {
    const result = try allocator.alloc([]u8, words.len);
    var pos: usize = 0;
    errdefer {
        for (result[0..pos]) |line| allocator.free(line);
        allocator.free(result);
    }
    var i: usize = 0;
    while (i + 1 < words.len) : (i += 1) {
        result[pos] = try fmt.allocPrint(allocator, "For want of a {s} the {s} was lost.\n", .{ words[i], words[i + 1] });
        pos += 1;
    }
    if (words.len > 0) result[pos] = try fmt.allocPrint(allocator, "And all for the want of a {s}.\n", .{words[0]});
    pos += 1;
    return result;
}
