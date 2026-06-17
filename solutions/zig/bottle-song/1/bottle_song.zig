const std = @import("std");

const letters = [_][]const u8{
    "no",   "one", "two",   "three", "four",
    "five", "six", "seven", "eight", "nine",
    "ten",
};

fn cap(n: u32) []const u8 {
    return switch (n) {
        1 => "One",
        2 => "Two",
        3 => "Three",
        4 => "Four",
        5 => "Five",
        6 => "Six",
        7 => "Seven",
        8 => "Eight",
        9 => "Nine",
        10 => "Ten",
        else => unreachable,
    };
}

fn bottleWord(n: u32) []const u8 {
    return if (n == 1) "bottle" else "bottles";
}

pub fn recite(buffer: []u8, start_bottles: u32, take_down: u32) ![]const u8 {
    std.debug.assert(start_bottles <= 10);
    std.debug.assert(take_down >= 1);
    std.debug.assert(take_down <= start_bottles);

    var pos: usize = 0;
    var n = start_bottles;
    var verse: u32 = 0;

    while (verse < take_down) : (verse += 1) {
        if (verse > 0) {
            const sep = try std.fmt.bufPrint(buffer[pos..], "\n\n", .{});
            pos += sep.len;
        }

        const text = try std.fmt.bufPrint(
            buffer[pos..],
            "{s} green {s} hanging on the wall,\n" ++
                "{s} green {s} hanging on the wall,\n" ++
                "And if one green bottle should accidentally fall,\n" ++
                "There'll be {s} green {s} hanging on the wall.",
            .{
                cap(n),
                bottleWord(n),
                cap(n),
                bottleWord(n),
                letters[n - 1],
                bottleWord(n - 1),
            },
        );

        pos += text.len;
        n -= 1;
    }

    return buffer[0..pos];
}
