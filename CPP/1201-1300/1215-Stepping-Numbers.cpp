class Solution {
public:
    void bt(string& str, set<int>& ans, const string& sl, const string& sh) {
        //char c = ans.back();
        //cout << str << endl;
        if (str.back() != '0') {
            char c = str.back() - 1;
            str += c;
            bool test(str.length() == sl.length() && str >= sl || str.length() > sl.length());

            if (str.length() == sh.length()) {
                if (test && str <= sh)
                    ans.insert(stoi(str));

            } else {
                if (test)
                    ans.insert(stoi(str));
                bt(str, ans, sl, sh);
            }
            str.pop_back();
        }



        if (str.back() != '9') {
            char c = str.back() + 1;
            str += c;
            bool test(str.length() == sl.length() && str >= sl || str.length() > sl.length());

            if (str.length() == sh.length()) {
                if (test && str <= sh)
                    ans.insert(stoi(str));

            } else {
                if (test)
                    ans.insert(stoi(str));
                bt(str, ans, sl, sh);
            }
            str.pop_back();
        }
    }

    vector<int> countSteppingNumbers(int low, int high) {
        set<int> ans;
        string sl(to_string(low)), sh(to_string(high));

        for (int i = low; i < 10; ++i)
            ans.insert(i);

        for (char c = '1'; c <= '9'; ++c) {
            string str(1, c);
            bt(str, ans, sl, sh);
        }

        return vector<int>(ans.begin(), ans.end());
    }
};
