pub const QueenError = error{
    InitializationFailure,
};

pub const Queen = struct {
    x: i8,
    y: i8,
    pub fn init(row: i8, col: i8) QueenError!Queen {
        if(row < 0 or col < 0) return QueenError.InitializationFailure;
        if(row > 7 or col > 7) return QueenError.InitializationFailure;
        return Queen{.x = row, .y = col};
    }

    pub fn canAttack(self: Queen, other: Queen) QueenError!bool {
        if(self.x < 0 or self.y < 0 or other.x < 0 or other.y < 0) return QueenError.InitializationFailure;
        if(self.x == other.x) return true;
        if(self.y == other.y) return true;
        if(@max(self.x, other.x) - @min(self.x, other.x) == @max(self.y, other.y) - @min(self.y, other.y)) return true;
        return false;
    }
};
