const std = @import("std");

pub fn isArmstrongNumber(num: u128) bool {
    const allocator = std.heap.page_allocator;
    const arr = std.fmt.allocPrint(allocator, "{}", .{num}) catch return false;
    defer allocator.free(arr);

    var result: u128 = 0;

    for(arr) |c| {
        result += std.math.pow(u128, c - @as(u8, '0'), arr.len);
    }
    return (num == result);
}
