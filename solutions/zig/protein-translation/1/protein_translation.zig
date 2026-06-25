const std = @import("std");
const mem = std.mem;

pub const TranslationError = error{
    InvalidCodon,
};

pub const Protein = enum {
    methionine,
    phenylalanine,
    leucine,
    serine,
    tyrosine,
    cysteine,
    tryptophan,
    stop,
};

pub fn proteins(allocator: mem.Allocator, strand: []const u8) (mem.Allocator.Error || TranslationError)![]Protein {
    const len = strand.len;
    var result = try std.ArrayList(Protein).initCapacity(allocator, 64);
    errdefer result.deinit(allocator);

    var i: usize = 0;
    while (i + 3 <= len) : (i += 3) {
        const codon = strand[i .. i + 3];
        const protein = try codonToProtein(codon);
        if (protein == .stop) return result.toOwnedSlice(allocator);
        try result.append(allocator, protein);
    }
    if (i != strand.len) return TranslationError.InvalidCodon;
    return result.toOwnedSlice(allocator);
}

fn codonToProtein(codon: []const u8) TranslationError!Protein {
    if (codon.len != 3) return TranslationError.InvalidCodon;
    if (std.mem.eql(u8, codon, "AUG")) {
        return .methionine;
    } else if (std.mem.eql(u8, codon, "UUU") or std.mem.eql(u8, codon, "UUC")) {
        return .phenylalanine;
    } else if (std.mem.eql(u8, codon, "UUA") or std.mem.eql(u8, codon, "UUG")) {
        return .leucine;
    } else if (std.mem.eql(u8, codon, "UCU") or std.mem.eql(u8, codon, "UCC") or std.mem.eql(u8, codon, "UCA") or std.mem.eql(u8, codon, "UCG")) {
        return .serine;
    } else if (std.mem.eql(u8, codon, "UAU") or std.mem.eql(u8, codon, "UAC")) {
        return .tyrosine;
    } else if (std.mem.eql(u8, codon, "UGU") or std.mem.eql(u8, codon, "UGC")) {
        return .cysteine;
    } else if (std.mem.eql(u8, codon, "UGG")) {
        return .tryptophan;
    } else if (std.mem.eql(u8, codon, "UAA") or std.mem.eql(u8, codon, "UAG") or std.mem.eql(u8, codon, "UGA")) {
        return .stop;
    }
    return TranslationError.InvalidCodon;
}
