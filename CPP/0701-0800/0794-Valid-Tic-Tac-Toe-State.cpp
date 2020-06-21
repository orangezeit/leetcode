class Solution {
public:
    int check(vector<int> s) {
        if (s.size() < 3) return true;
        for (int i = 0; i + 2 < s.size(); ++i) {
            for (int j = i + 1; j + 1 < s.size(); ++j) {
                for (int k = j + 1; k < s.size(); ++k) {
                    if ((s[i] == 0 && s[j] == 1 && s[k] == 2) ||
                        (s[i] == 3 && s[j] == 4 && s[k] == 5) ||
                        (s[i] == 6 && s[j] == 7 && s[k] == 8) ||
                        (s[i] == 0 && s[j] == 3 && s[k] == 6) ||
                        (s[i] == 1 && s[j] == 4 && s[k] == 7) ||
                        (s[i] == 2 && s[j] == 5 && s[k] == 8) ||
                        (s[i] == 0 && s[j] == 4 && s[k] == 8) ||
                        (s[i] == 2 && s[j] == 4 && s[k] == 6)) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
    bool validTicTacToe(vector<string>& board) {
        vector<int> x, o;

        for (int i = 0; i < 9; ++i) {
            if (board[i / 3][i % 3] == 'X') x.push_back(i);
            else if (board[i / 3][i % 3] == 'O') o.push_back(i);

            if (x.size() > 5 || o.size() > 5) return false;
        }

        return (x.size() == o.size() && check(x)) || (x.size() == o.size() + 1 && check(o));
    }
};
