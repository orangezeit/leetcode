class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // ul: up-left, u: up, ur: up-right
        // l: left, r: right
        // dl: down-left, d: down, dr: down-right

        // Time Complexity: O(n)
        // Space Complexity: O(1)

        unordered_map<string, pair<int, vector<int>>> rec;
        for (const vector<int>& queen: queens) {
            int dx(queen[0] - king[0]), dy(queen[1] - king[1]);
            if (dx == 0) {
                if (dy < 0) {
                    if (!rec.count("l") || rec["l"].first > -dy)
                        rec["l"] = {-dy, queen};
                } else {
                    if (!rec.count("r") || rec["r"].first > dy)
                        rec["r"] = {dy, queen};
                }
            } else if (dy == 0) {
                if (dx < 0) {
                    if (!rec.count("u") || rec["u"].first > -dx)
                        rec["u"] = {-dx, queen};
                } else {
                    if (!rec.count("d") || rec["d"].first > dx)
                        rec["d"] = {dx, queen};
                }
            } else if (abs(dx) == abs(dy)) {
                if (dx < 0 && dy < 0) {
                    if (!rec.count("ul") || rec["ul"].first > -dx)
                        rec["ul"] = {-dx, queen};
                } else if (dx < 0 && dy > 0) {
                    if (!rec.count("ur") || rec["ur"].first > -dx)
                        rec["ur"] = {-dx, queen};
                } else if (dx > 0 && dy < 0) {
                    if (!rec.count("dl") || rec["dl"].first > dx)
                        rec["dl"] = {dx, queen};
                } else {
                    if (!rec.count("dr") || rec["dr"].first > dx)
                        rec["dr"] = {dx, queen};
                }
            }
        }

        vector<vector<int>> ans;

        for (const auto& p: rec)
            ans.push_back(p.second.second);

        return ans;
    }
};
