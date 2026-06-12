const std = @import("std");
const mem = std.mem;

pub fn abbreviate(allocator: mem.Allocator, words: []const u8) mem.Allocator.Error![]u8 {
    const buff = try allocator.alloc(u8, words.len);
    
    var pos: u32 = 0;
    var wordstart = true;
    for(words[0..(words.len-1)]) |c| {
        switch(c){
            ' ', '_', '-' => {
                wordstart = true;
                continue;
            },
            else => {},
        }
        if(wordstart){
            buff[pos] = std.ascii.toUpper(c);
            pos += 1;
            wordstart = false;
        }
    }

    return try allocator.realloc(buff, pos);
}
