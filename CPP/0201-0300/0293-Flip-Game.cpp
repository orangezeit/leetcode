class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> moves;

        if (s.empty())
            return moves;

        for(int i = 0; i < s.length()-1; ++i) {
            if (s[i] == '+' && s[i+1] == '+') {
                s[i] = '-';
                s[i+1] = '-';
                moves.push_back(s);
                s[i] = '+';
                s[i+1] = '+';
            }
        }

        return moves;
    }
};
