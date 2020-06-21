class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx < tx && sy < ty)
            tx < ty ? ty %= tx : tx %= ty;
        return sx == tx && sy <= ty && (ty - sy) % tx == 0 || sy == ty && sx <= tx && (tx - sx) % ty == 0;
    }
};
