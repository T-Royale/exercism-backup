pub const ComputationError = error{
    IllegalArgument,
};

pub fn steps(number: usize) anyerror!usize {
    if (number == 0) return ComputationError.IllegalArgument;
    var n = number;
    var result: usize = 0;
    while (n != 1) : (result += 1) {
        if (n & 1 == 1) {   // Odd
            n = (n * 3) + 1;
        } else {            // Even
            n /= 2;
        }
    }
    return result;
}
