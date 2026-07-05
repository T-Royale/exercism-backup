const std = @import("std");

const marked: u32 = 1;
const unmarked: u32 = 0;

pub fn primes(buffer: []u32, limit: u12) []u32 {
    if (limit < 2) return buffer[0..0];

    const max: usize = limit;
    const sieve_len: usize = max - 1; // numbers 2 through limit

    var sieve: [4094]u32 = @splat(unmarked);
    const marks = sieve[0..sieve_len];

    var p: usize = 2;
    while (p * p <= max) : (p += 1) {
        if (marks[p - 2] == unmarked) {
            var multiple: usize = p * p;

            while (multiple <= max) : (multiple += p) {
                marks[multiple - 2] = marked;
            }
        }
    }
    var pos: usize = 0;
    for (marks, 0..) |c, i| {
        if (c == unmarked) {
            buffer[pos] = @intCast(i + 2);
            pos += 1;
        }
    }
    return buffer[0..pos];
}
