const std = @import("std");
const EnumSet = std.EnumSet;

pub const Allergen = enum {
    eggs,
    peanuts,
    shellfish,
    strawberries,
    tomatoes,
    chocolate,
    pollen,
    cats,
};

pub fn isAllergicTo(score: u8, allergen: Allergen) bool {
    const set = initAllergenSet(score);
    return set.contains(allergen);
}

pub fn initAllergenSet(score: usize) EnumSet(Allergen) {
    var result = EnumSet(Allergen).init(.{});
    var s = score;
    
    for (std.enums.values(Allergen)) |allergen|{
        if(s & 1 == 1){
            result.insert(allergen);
        }
        s >>= 1;
    }
    return result;
}
