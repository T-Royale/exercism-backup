const std = @import("std");
const mem = std.mem;

pub const ColorBand = enum(usize) {
    black,
    brown,
    red,
    orange,
    yellow,
    green,
    blue,
    violet,
    grey,
    white,
};

fn get_code(color: ColorBand) usize {
    return switch (color) {
        .black => 0,
        .brown => 1,
        .red => 2,
        .orange => 3,
        .yellow => 4,
        .green => 5,
        .blue => 6,
        .violet => 7,
        .grey => 8,
        .white => 9,
    };
}
const Unit = struct {
    value: usize,
    name: []const u8,
};

const units = [_]Unit{
    .{ .value = 1_000_000_000, .name = "giga" },
    .{ .value = 1_000_000,     .name = "mega" },
    .{ .value = 1_000,         .name = "kilo" },
    .{ .value = 1,             .name = "" },
};

pub fn label(allocator: mem.Allocator, colors: []const ColorBand) mem.Allocator.Error![]u8 {
    var value: usize = get_code(colors[0]) * 10 + get_code(colors[1]);
    value *= std.math.pow(usize, 10, get_code(colors[2]));

    if (value == 0) {
        return try std.fmt.allocPrint(allocator, "0 ohms", .{});
    }

    for (units) |unit| {
        if (value >= unit.value) {
            const whole = value / unit.value;
            const decimal = (value % unit.value) * 10 / unit.value;

            if (decimal == 0) {
                return try std.fmt.allocPrint(
                    allocator,
                    "{d} {s}ohms",
                    .{ whole, unit.name },
                );
            }

            return try std.fmt.allocPrint(
                allocator,
                "{d}.{d} {s}ohms",
                .{ whole, decimal, unit.name },
            );
        }
    }
    unreachable;
}
