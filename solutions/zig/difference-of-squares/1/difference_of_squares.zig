pub fn squareOfSum(number: usize) usize {
    var result: usize = 0;
    for (0..number+1) |i| {
        result += i;
    }
    result *= result; 
    return result;
}

pub fn sumOfSquares(number: usize) usize {
    const result = (number*(number+1)*((2*number)+1))/6;
    return result;
}

pub fn differenceOfSquares(number: usize) usize {
    const result = squareOfSum(number) - sumOfSquares(number);
    return result;
}
