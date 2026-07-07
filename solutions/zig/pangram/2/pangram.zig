const std = @import("std");

pub fn isPangram(str: []const u8) bool {
    if (str.len < 26) return false;
    var bitset = std.bit_set.IntegerBitSet(26).initEmpty();
    for (str) |c| {
        if (!std.ascii.isAlphabetic(c)) continue;
        const index = std.ascii.toLower(c) - @as(u8, 'a');
        bitset.set(index);
    }
    return (bitset.count() == 26);
}
