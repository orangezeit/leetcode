class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shifts) {
        int moves(0);
        for (const vector<int>& shift: shifts)
            moves += shift[0] ? (s.length() - shift[1]) : shift[1];
        rotate(s.begin(), s.begin() + (s.length() + moves) % s.length(), s.end());
        return s;
    }
};
