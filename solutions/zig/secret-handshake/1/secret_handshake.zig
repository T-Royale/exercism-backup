const std = @import("std");
const mem = std.mem;

pub const Signal = enum {
    wink,
    double_blink,
    close_your_eyes,
    jump,
};

pub fn calculateHandshake(allocator: mem.Allocator, number: u5) ![]const Signal {
    var result = try std.ArrayList(Signal).initCapacity(allocator, 1);
    errdefer result.deinit(allocator);

    var n: u5 = number;

    if (n & 1 == 1) {
        try result.append(allocator, .wink);
    }
    n >>= 1;
    if (n & 1 == 1) {
        try result.append(allocator, .double_blink);
    }
    n >>= 1;
    if (n & 1 == 1) {
        try result.append(allocator, .close_your_eyes);
    }
    n >>= 1;
    if (n & 1 == 1) {
        try result.append(allocator, .jump);
    }
    n >>= 1;
    // Reverse order
    if (n & 1 == 1) {
        std.mem.reverse(Signal, result.items);
    }

    return try result.toOwnedSlice(allocator);
}
