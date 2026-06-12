pub const TriangleError = error{
    Invalid,
};

pub const Triangle = struct {
    a: f64 = 0,
    b: f64 = 0,
    c: f64 = 0,

    pub fn init(side_a: f64, side_b: f64, side_c: f64) TriangleError!Triangle {
        if (side_a <= 0 or side_b <= 0 or side_c <= 0) return TriangleError.Invalid;
        if (side_a + side_b <= side_c or side_a + side_c <= side_b or side_b + side_c <= side_a) return TriangleError.Invalid;
        return Triangle{
            .a = side_a,
            .b = side_b,
            .c = side_c,
        };
    }

    pub fn isEquilateral(self: Triangle) bool {
        return (self.a == self.b and self.b == self.c);
    }

    pub fn isIsosceles(self: Triangle) bool {
        return (self.a == self.b or self.b == self.c or self.a == self.c);
    }

    pub fn isScalene(self: Triangle) bool {
        return (!isEquilateral(self) and !isIsosceles(self));
    }
};
