class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int a[8] = {};
        bool player(true);

        for (const vector<int>& m: moves) {
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 3; ++j)
                    if (m[i] == j)
                        player ? a[i * 3 + j]++ : a[i * 3 + j]--;
            if (m[0] == m[1]) player ? a[6]++ : a[6]--;
            if (m[0] == 2 - m[1]) player ? a[7]++ : a[7]--;
            for (int i = 0; i < 8; ++i)
                if (a[i] == 3) return "A";
                else if (a[i] == -3) return "B";
            player = !player;
        }
        for (int i = 0; i < 8; ++i) cout << a[i] << ' ';
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
