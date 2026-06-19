const std = @import("std");

pub fn isValidIsbn10(s: []const u8) bool {
    var buff: [10]usize = @splat(0);
    var pos: u16 = 0;

    for (s) |c| {
        if (c == '-') continue;
        if (std.ascii.isDigit(c)) {
            if (pos >= 10) return false;
            buff[pos] = c - @as(u8, '0');
        } else if (c == 'X') {
            if (pos != 9) return false;
            buff[pos] = 10;
        } else return false;
        pos += 1;
    }

    if (pos != 10) return false;

    var result: usize = 0;
    for (buff[0..pos], 0..) |n, i| {
        result += n * (10 - i);
    }

    return (result % 11 == 0);
}
