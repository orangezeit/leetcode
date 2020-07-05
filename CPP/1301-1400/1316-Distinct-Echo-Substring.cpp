class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> ans;
        for (int i = 0; i < text.length() - 1; ++i) {
            string ss1, ss2;
            ss1 += text[i];
            ss2 += text[i + 1];
            if (ss1 == ss2) ans.insert(ss1);
            int k = 1;
            while (i + k + 2 < text.length()) {
                ss1 += ss2[0];
                ss2.erase(ss2.begin());
                ss2 += text[i + k + 1];
                ss2 += text[i + k + 2];
                if (ss1 == ss2) {
                    ans.insert(ss1);
                    //cout << ss1 << " " << ss2 << endl;
                    //ans++;
                }
                k += 2;
            }
        }
        return ans.size();
    }
};
