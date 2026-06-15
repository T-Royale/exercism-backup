// Integer square root: Linear search
pub fn squareRoot(radicand: usize) usize {
    var L: usize = 0;
    while ((L + 1) * (L + 1) <= radicand) {
        L += 1;
    }
    return L;
}
