class Solution {
public:
    void comb(const vector<set<string>>& vs, int i, string& str, set<string>& ans) {
        if (i == vs.size()) {
            ans.insert(str);
            return;
        }

        for (const string& s: vs[i]) {
            string temp(str);
            str += s;
            comb(vs, i + 1, str, ans);
            str = temp;
        }
    }
    set<string> helper(string ep) {
        if (ep.length() == 1) return {ep};

        int k = 0;
        vector<string> strs = {""};
        bool enter(false);

        for (const char& c: ep) {
            if (c == '{') {
                enter = true;
                k++;
            } else if (c == '}') {
                k--;
            }
            strs.back() += c;
            if (!k) strs.push_back("");
        }
        if (strs.back().empty()) strs.pop_back();
        set<string> ans;

        if (strs.size() == 1) {
            strs[0].clear();
            for (int i = 1; i < ep.length() - 1; ++i) {
                if (ep[i] == '{') k++;
                else if (ep[i] == '}') k--;
                if (ep[i] == ',' && !k) strs.push_back("");
                else strs.back() += ep[i];
            }

            for (const string& str: strs) {
                set<string> ss = helper(str);
                for (const string& st: ss)
                    ans.insert(st);
            }
        } else {
            if (!enter) return {ep};
            vector<set<string>> vs(strs.size());
            for (int i = 0; i < strs.size(); ++i) {
                vs[i] = helper(strs[i]);
            }
            string sss;
            comb(vs, 0, sss, ans);
        }
        return ans;
    }
    vector<string> braceExpansionII(string ep) {
        set<string> ss = helper(ep);
        return vector<string>(ss.begin(), ss.end());
    }
};
