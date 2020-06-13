class Solution {
public:
    char digits[5] = {'0', '1', '6', '8', '9'};
    char counters[5] = {'0', '1', '9', '8', '6'};
    vector<string> ans;

    bool isValid(const string& num, const string& str) {
        if (num.length() == str.length() && num > str) return false;
        string counter(num.length(), '0');
        for (int i = 0; i < num.length(); ++i)
            counter[i] = num[i] == '6' ? '9' : num[i] == '9' ? '6' : num[i];
        reverse(counter.begin(), counter.end());

        return num != counter;

    }

    void bt(string num, const string& str, int len) {
        if (!len) return;

        for (int i = 0; i < 5; ++i) {
            if (num.empty() && !i) continue;
            num += digits[i];
            bt(num, str, len-1);
            if (isValid(num, str))
                ans.push_back(num);
            num.pop_back();
        }
    }

    int confusingNumberII(int N) {
        string str = to_string(N);
        bt("", str, str.length());
        //for (const string& s: ans)
            //cout << s << endl;
        return ans.size();
    }
};
