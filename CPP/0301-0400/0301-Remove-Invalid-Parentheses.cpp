struct infos {
    int balance;
    vector<int> removed;
    infos(int b, vector<int> r): balance(b), removed(r) {}
};

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int maxLen(0), p(0);

        for (const char& c: s) {
            if (c == '(') {
                p++;
            } else if (c == ')') {
                if (p) {
                    p--;
                    maxLen += 2;
                }
            } else {
                maxLen++;
            }
        }

        queue<infos> q;
        unordered_set<string> ans;
        int i(0);
        q.push(infos(0, {}));

        while(!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int b = q.front().balance;
                vector<int> r = q.front().removed;

                q.pop();


                while (i < s.length() && s[i] != '(' && s[i] != ')') i++;

                if (i == s.length()) {
                    if (b == 0 && r.size() + maxLen == s.length()) {
                        string t(s);
                        for (int k = r.size() - 1; k >= 0; --k)
                            t.erase(t.begin() + r[k]);
                        ans.insert(t);
                    }
                    //continue;
                } else {
                    b += s[i] == '(' ? 1 : -1;
                    if (b >= 0) q.push(infos(b, r));
                    b += s[i] == '(' ? -1 : 1;
                    if (r.size() + maxLen == s.length()) continue;
                    r.push_back(i);
                    //t[i] = '*';
                    if (b >= 0) q.push(infos(b, r));
                }
            }
            i++;
        }

        return vector<string>(ans.begin(), ans.end());
    }
};
