const std = @import("std");

pub fn modifier(score: i8) i8 {
    const result = @divFloor(score - 10, 2);
    return result;
}

var prng = std.Random.DefaultPrng.init(0x12345678);

pub fn ability() i8 {
    const rand = prng.random();

    var arr: [4]u8 = @splat(0);

    for (&arr) |*n| {
        n.* = rand.intRangeAtMost(u8, 1, 6);
    }

    std.sort.pdq(u8, arr[0..], {}, std.sort.asc(u8));

    var result: u8 = 0;
    for (arr[1..]) |n| {
        result += n;
    }

    return @intCast(result);
}

// Your character's initial hitpoints are 10 + your character's constitution modifier.
pub const Character = struct {
    strength: i8,
    dexterity: i8,
    constitution: i8,
    intelligence: i8,
    wisdom: i8,
    charisma: i8,
    hitpoints: i8,

    pub fn init() Character {
        var result: Character = .{
            .strength = ability(),
            .dexterity = ability(),
            .constitution = ability(),
            .intelligence = ability(),
            .wisdom = ability(),
            .charisma = ability(),
            .hitpoints = 0,
        };
        result.hitpoints = 10 + modifier(result.constitution);
        return result;
    }
};
