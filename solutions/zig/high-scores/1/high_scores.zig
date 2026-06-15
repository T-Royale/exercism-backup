const std = @import("std");

pub const HighScores = struct {
    scores: []const i32,
    top_three: [3]i32,
    top_three_len: usize,

    pub fn init(scores: []const i32) HighScores {
        const n = @min(3, scores.len);
        var hs = HighScores{
            .scores = scores,
            .top_three = undefined,
            .top_three_len = n,
        };

        for (0..n) |i| hs.top_three[i] = scores[i];
        std.sort.pdq(i32, hs.top_three[0..n], {}, std.sort.desc(i32));

        for (scores[n..]) |score| {
            if (score > hs.top_three[n - 1]) {
                hs.top_three[n - 1] = score;
                std.sort.pdq(i32, hs.top_three[0..n], {}, std.sort.desc(i32));
            }
        }

        return hs;
    }

    pub fn latest(self: *const HighScores) ?i32 {
        const len = self.scores.len;
        return if (len == 0) null else self.scores[len - 1];
    }

    pub fn personalBest(self: *const HighScores) ?i32 {
        const idx = std.sort.argMax(i32, self.scores, {}, std.sort.asc(i32));
        return if (idx == null) null else self.scores[idx.?];
    }

    pub fn personalTopThree(self: *const HighScores) []const i32 {
        return self.top_three[0..self.top_three_len];
    }
};
