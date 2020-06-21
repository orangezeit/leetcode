class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {

        int oneline = 0;
        int lines = 1;
        //int last = 0;

        for (int i = 0; i < S.length(); ++i) {
            oneline += widths[S[i] - 'a'];
            if (oneline > 100) {
                lines++;
                oneline = widths[S[i] - 'a'];
            }
        }

        vector<int> ans = {lines, oneline};

        return ans;
    }
};
