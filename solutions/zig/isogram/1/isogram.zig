const std = @import("std");

pub fn isIsogram(str: []const u8) bool {
    const size = @as(u8, 'z') - @as(u8, 'a') + 1;
    var buff: [size]bool = @splat(false);

    for(str) |c| {
        if(!std.ascii.isAlphabetic(c)) continue;
        const pos = std.ascii.toLower(c) - @as(u8, 'a');
        if(buff[pos]) {
            return false;
        } else buff[pos] = true;
    }
    return true;
}