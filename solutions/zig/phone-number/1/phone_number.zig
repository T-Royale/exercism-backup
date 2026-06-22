const ascii = @import("std").ascii;

pub fn clean(phrase: []const u8) ?[10]u8 {
    if (phrase.len < 10) return null;
    var result: [10]u8 = @splat(0);

    var i: usize = 0;
    var pos: u8 = 0;
    if (phrase[0] == '1') i = 1;
    if (phrase[0] == '+' and phrase[1] == '1') i = 2;

    while (i < phrase.len) : (i += 1) {
        const c = phrase[i];
        if (ascii.isDigit(c)) {
            if ((pos == 0 or pos == 3) and (c == '1' or c == '0')) return null;
            if (pos >= 10) return null;
            result[pos] = c;
            pos += 1;
        }
    }
    if (pos != 10) return null;
    return result;
}
