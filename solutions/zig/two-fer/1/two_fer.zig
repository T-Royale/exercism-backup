const std = @import("std");

pub fn twoFer(buffer: []u8, name: ?[]const u8) ![]u8 {
    const who = name orelse "you";
    return try std.fmt.bufPrint(buffer, "One for {s}, one for me.", .{who});
}
