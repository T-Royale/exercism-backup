pub fn eggCount(number: usize) usize {
    var n = number;
    var result: usize = 0;
    while(n > 0) : (n >>= 1){
        if(n & 1 == 1) result += 1;
    }
    return result;
}
