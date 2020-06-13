/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &bm) {
        vector<int> rc = bm.dimensions();
        int r(-1), c(rc[1]);
        while (++r < rc[0])
            while (c && bm.get(r, c - 1))
                c--;
        return c == rc[1] ? -1 : c;
    }
};
