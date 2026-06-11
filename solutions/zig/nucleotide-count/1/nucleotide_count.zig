const std = @import("std");

pub const NucleotideError = error{Invalid};

pub const Counts = struct {
    a: u32,
    c: u32,
    g: u32,
    t: u32,
};

pub fn countNucleotides(s: []const u8) NucleotideError!Counts {
    var result = std.mem.zeroes(Counts);
    for(s) |c| {
        switch(c){
            'A' => result.a += 1,
            'C' => result.c += 1,
            'G' => result.g += 1,
            'T' => result.t += 1,
            else => return NucleotideError.Invalid,
        }
    }
    return result;
}
