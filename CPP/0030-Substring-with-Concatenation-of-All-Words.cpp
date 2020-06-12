class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> m;
        vector<int> ans;
        int a(s.length()), c(words.size());
        if (!a || !c) return ans;
        int b(words[0].length());
        for (const string& w: words)
            m[w]++;
        for (int i = 0; i <= a - b * c; ++i) {
            int k = i;
            unordered_map<string, int> mc(m);
            while (k < s.length() || mc.empty()) {
                string str = s.substr(k, b);
                if (mc.count(str)) {
                    if (!(--mc[str]))
                        mc.erase(str);
                } else {
                    break;
                }
                k += b;
            }
            if (mc.empty()) ans.push_back(i);
        }
        
        return ans;
    }
};
