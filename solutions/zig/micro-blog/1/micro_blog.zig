const std = @import("std");

pub fn truncate(phrase: []const u8) []const u8 {
    const MAX_LEN = 5;
    if (phrase.len <= MAX_LEN) return phrase;

    const view = std.unicode.Utf8View.init(phrase) catch unreachable;
    var iterator = view.iterator();
    var offset: usize = 0;
    var i: usize = 0;
    while (iterator.nextCodepointSlice()) |cp| : (i += 1) {
        if(i == MAX_LEN) break;
        offset += cp.len;
    }
    return phrase[0..offset];
}
