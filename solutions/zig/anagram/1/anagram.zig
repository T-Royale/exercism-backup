const std = @import("std");
const mem = std.mem;

/// Returns the set of strings in `candidates` that are anagrams of `word`.
/// Caller owns the returned memory.
pub fn detectAnagrams(
    allocator: mem.Allocator,
    word: []const u8,
    candidates: []const []const u8,
) !std.BufSet {
    var result = std.BufSet.init(allocator);
    errdefer result.deinit();

    const word_sorted = try allocator.alloc(u8, word.len);
    defer allocator.free(word_sorted);

    for (word, 0..) |c, i| word_sorted[i] = std.ascii.toLower(c);
    std.sort.pdq(u8, word_sorted, {}, std.sort.asc(u8));

    const buff = try allocator.alloc(u8, word.len);
    defer allocator.free(buff);

    loop_candidates: for (candidates) |candidate| {
        if (word.len != candidate.len) continue;
        if (std.ascii.eqlIgnoreCase(word, candidate)) continue;
        
        for (candidate, 0..) |c, i| buff[i] = std.ascii.toLower(c);
        std.sort.pdq(u8, buff, {}, std.sort.asc(u8));
        
        for (buff, word_sorted) |b, w| {
            if (b != w) continue :loop_candidates;
        }
        try result.insert(candidate);
    }
    return result;
}
