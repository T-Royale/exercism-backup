// Take a look at the tests, you might have to change the function arguments

pub fn binarySearch(comptime T: type, target: T, items: []const T) ?usize {
    const len = items.len;
    if (len == 0) return null;

    var top: usize = len;
    var bottom: usize = 0;
    while (top > bottom) {
        const current = bottom + ((top - bottom) / 2);
        const data = items[current];
        if (data == target) return current;
        if (data < target) {
            bottom = current + 1;
        } else {
            top = current;
        }
    }
    return null;
}
