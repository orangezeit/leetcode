class Solution {
public:
    void permutate(const vector<char>& digits, set<string>& ans, string temp) {
        if (temp.length() == 5) {
            if (temp.substr(3, 2) >= "60") return;
            ans.insert(temp);
        } else {
            if (temp.length() == 2) {
                if (temp >= "24") return;
                temp += ':';
            }

            for (int i = 0; i < 5; ++i) {
                if (i == 2) continue;
                permutate(digits, ans, temp + digits[i]);
            }
        }
    }

    string nextClosestTime(string time) {
        vector<char> digits(time.begin(), time.end());
        set<string> ans;
        string temp;
        permutate(digits, ans, temp);

        for (auto it = ans.begin(); it != ans.end(); ++it) {
            if (*it == time) {
                ++it;
                return it == ans.end() ? *ans.begin() : *it;
            }
        }

        return "";
    }
};
