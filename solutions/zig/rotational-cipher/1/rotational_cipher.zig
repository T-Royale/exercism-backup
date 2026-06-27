const std = @import("std");
const mem = std.mem;

pub fn rotate(allocator: mem.Allocator, text: []const u8, shiftKey: u5) mem.Allocator.Error![]u8 {
    const len = text.len;
    const result = try allocator.alloc(u8, len);
    errdefer allocator.free(result);

    for (text, result) |t, *r| {
        if (std.ascii.isAlphabetic(t)) {
            const base: u8 = if (std.ascii.isUpper(t)) 'A' else 'a';
            r.* = base + @as(u8, @intCast((t - base + shiftKey) % 26));
        } else r.* = t;
    }

    return result;
}
