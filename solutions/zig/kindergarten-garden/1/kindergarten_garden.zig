const std = @import("std");

pub const Plant = enum {
    clover,
    grass,
    radishes,
    violets,
};

const Students = enum(u8) {
    Alice = 0,
    Bob = 1,
    Charlie = 2,
    David = 3,
    Eve = 4,
    Fred = 5,
    Ginny = 6,
    Harriet = 7,
    Ileana = 8,
    Joseph = 9,
    Kincaid = 10,
    Larry = 11,
};

fn get_value(student: []const u8) u8 {
    const result = std.meta.stringToEnum(Students, student) orelse unreachable;
    return @intFromEnum(result);
}

fn get_plant(plant: u8) Plant {
    return switch (plant) {
        'C' => .clover,
        'G' => .grass,
        'R' => .radishes,
        'V' => .violets,
        else => unreachable,
    };
}

pub fn plants(diagram: []const u8, student: []const u8) [4]Plant {
    const value = get_value(student);
    const diagram_row = (diagram.len / 2) + 1; // Skip \n
    var result: [4]Plant = undefined;
    result[0] = get_plant(diagram[(value * 2)]);
    result[1] = get_plant(diagram[(value * 2) + 1]);
    result[2] = get_plant(diagram[(value * 2) + diagram_row]);
    result[3] = get_plant(diagram[(value * 2) + diagram_row + 1]);
    return result;
}
