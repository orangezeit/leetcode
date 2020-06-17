class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int tri[3] = {a, b, c};
        sort(tri, tri + 3);
        tri[2] -= tri[1] + 1;
        tri[1] -= tri[0] + 1;

        return {!tri[1] && !tri[2] ? 0 : tri[1] < 2 || tri[2] < 2 ? 1 : 2, tri[1] + tri[2]};
    }
};
