class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string str;
        for (const string& s: sentence) str += s + ' ';
        int n(str.length());
        int cnt(0);
        for (int i = 0; i < rows; ++i) {
            cnt += cols;
            if (str[cnt % n] == ' ') cnt++;
            else {
                while (cnt && str[(cnt-1) % n] != ' ') cnt--;
            }
        }
        return cnt / n;
    }
};
