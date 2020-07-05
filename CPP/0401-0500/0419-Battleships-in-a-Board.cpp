class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt(0);
        for (int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.')&& (j == 0 || board[i][j - 1] == '.'))
                    cnt++;
            }
        return cnt;
    }
};
