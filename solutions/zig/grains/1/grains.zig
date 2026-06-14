pub const ChessboardError = error{
    IndexOutOfBounds,
};

pub fn square(index: usize) ChessboardError!u64 {
    if (index == 0 or index > 64) return ChessboardError.IndexOutOfBounds;
    return @as(u64, 1) << @intCast(index - 1);
}

pub fn total() u64 {
    var result: u64 = 0;
    for(0..64) |i| {
        result |= @as(u64, 1) << @intCast(i);
    }
    return result;
}
