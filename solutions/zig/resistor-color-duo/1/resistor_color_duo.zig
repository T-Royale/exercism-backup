pub const ColorBand = enum(usize) {
    black, brown, red, orange, yellow,
    green, blue, violet, grey, white,
};

pub fn colorCode(colors: [2]ColorBand) usize {
    var result: usize = 0;

    result = get_code(colors[1]);
    result += (get_code(colors[0]) * 10);

    return result;
}

fn get_code(color: ColorBand) usize {
    return switch(color){
        .black => 0, .brown => 1, .red => 2, .orange => 3, .yellow => 4,
        .green => 5, .blue => 6, .violet => 7, .grey => 8, .white => 9,
    };
}

