class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string ans;

        for (string& s: strs) {
            string t(s.rbegin(), s.rend());
            if (t > s) s = t;
        }

        for (int i = 0; i < strs.size(); ++i) {

            string t1(strs[i]), t2(t1.rbegin(), t1.rend());

            for (int j = 1; j < strs.size(); ++j) {
                t1 += strs[(i + j) % strs.size()];
                t2 += strs[(i + j) % strs.size()];
            }

            ans = max(ans, t1);
            ans = max(ans, t2);

            for (int j = 1; j < strs[i].length(); ++j) {
                t1 += t1[0];
                t1.erase(t1.begin());
                t2 += t2[0];
                t2.erase(t2.begin());
                ans = max(ans, t1);
                ans = max(ans, t2);
            }
        }

        return ans;
    }
};
