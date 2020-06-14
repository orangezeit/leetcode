class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<int> rec(s.length() + 1, 0);

        for (int i = 0; i < dict.size(); ++i) {
            size_t it = s.find(dict[i]);
            while (it != string::npos) {
                rec[it]++;
                rec[it + dict[i].length()]--;
                it = s.find(dict[i], it + 1);
            }
        }

        bool flag = false;
        int idx = 0;
        vector<int> ist;

        for (int i = 0; i <= s.length(); ++i) {
            idx += rec[i];
            if ((bool)idx ^ flag) {
                flag = !flag;
                ist.push_back(i);
            }
        }
        string bold[2] = {"<b>", "</b>"};
        for (int i = ist.size() - 1; i >= 0; --i)
            s.insert(ist[i], bold[i % 2]);
        return s;
    }
};
