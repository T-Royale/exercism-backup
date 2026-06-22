const math = @import("std").math;

pub const Classification = enum {
    deficient,
    perfect,
    abundant,
};

pub fn classify(n: u64) Classification {
    if (n == 0) unreachable;
    if (n == 1) return .deficient;
    var sum: usize = 1;
    var i: usize = 2;
    while (i * i <= n) : (i += 1) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    if (sum > n) return .abundant;
    if (sum < n) return .deficient;
    return .perfect;
}
