class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        text += ' ';
        int k = 0;
        stack<string> s;
        vector<string> ans;

        for (int i = 0; i < text.length(); ++i)
            if (text[i] == ' ') {
                s.push(text.substr(k, i - k));
                k = i + 1;
            }

        if (s.size() < 3) return ans;

        string fi, se, th;
        th = s.top();
        s.pop();
        se = s.top();
        s.pop();

        while (!s.empty()) {
            fi = s.top();
            s.pop();
            if (fi == first && se == second) ans.push_back(th);
            th = se;
            se = fi;
        }

        return ans;
    }
};
