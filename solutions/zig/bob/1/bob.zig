const std = @import("std");
const ascii = std.ascii;

pub fn response(s: []const u8) []const u8 {
    var hasLetter = false;
    var hasLower = false;
    var lastNonSpace:u8 = 0;

    for(s) |c|{
        if(!ascii.isWhitespace(c)) lastNonSpace = c;
        if(ascii.isAlphabetic(c)){
            hasLetter = true;
            if(ascii.isLower(c)){
                hasLower = true;
            }
        }
    }

    const silence = (lastNonSpace == 0);
    const question = (lastNonSpace == '?');
    const yelling = (hasLetter and !hasLower);

    if (silence) {
        return "Fine. Be that way!";
    } else if (question and yelling) {
        return "Calm down, I know what I'm doing!";
    } else if (question) {
        return "Sure.";
    } else if (yelling) {
        return "Whoa, chill out!";
    } else {
        return "Whatever.";
    }
}
