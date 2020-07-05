class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string lo(to_string(low)), hi(to_string(high));
        for (int len = lo.length(); len <= hi.length(); ++len) {
            for (char c = '1'; c <= '9' - len + 1; ++c) {
                string temp;
                for (int i = 0; i < len; ++i) {
                    temp += (c + i);
                }
                if (len == lo.length() && len == hi.length()) {
                    if (temp >= lo && temp <= hi) ans.push_back(stoi(temp));
                } else if (len == lo.length()) {
                    if (temp >= lo) ans.push_back(stoi(temp));
                } else if (len == hi.length()) {
                    if (temp <= hi) ans.push_back(stoi(temp));
                } else {
                    ans.push_back(stoi(temp));
                }

            }
        }
        return ans;
    }
};
