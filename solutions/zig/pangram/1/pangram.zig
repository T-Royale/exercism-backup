const std = @import("std");

pub fn isPangram(str: []const u8) bool {
    var result: u32 = 0;
    for(str) |char| {
        if(!std.ascii.isAlphabetic(char)) continue;
        const c = std.ascii.toLower(char);
        const index: u5 = @intCast(c - 'a');
        result |= @as(u32, 1) << index;
    }
    return (result == (@as(u32, 1) << 26) - 1);
}
