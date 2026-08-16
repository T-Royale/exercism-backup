const std = @import("std");

pub const Relation = enum {
    equal,
    sublist,
    superlist,
    unequal,
};

pub fn compare(list_one: []const i32, list_two: []const i32) Relation {
    if (list_one.len == 0 and list_two.len == 0) return .equal;
    if (list_one.len == 0) return .sublist;
    if (list_two.len == 0) return .superlist;
    if (list_one.len == list_two.len) {
        if (std.mem.eql(i32, list_one, list_two)) {
            return .equal;
        } else return .unequal;
    }
    if (list_one.len < list_two.len) {
        for (list_two, 0..) |element, i| {
            if (element == list_one[0]) {
                if (list_two.len >= list_one.len + i) {
                    if (std.mem.eql(i32, list_one, list_two[i .. i + list_one.len])) {
                        return .sublist;
                    }
                } else return .unequal;
            }
        }
    } else {
        for (list_one, 0..) |element, i| {
            if (element == list_two[0]) {
                if (list_one.len >= list_two.len + i) {
                    if (std.mem.eql(i32, list_two, list_one[i .. i + list_two.len])) {
                        return .superlist;
                    }
                } else return .unequal;
            }
        }
    }
    return .unequal;
}
