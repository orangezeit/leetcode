class Solution {
public:
    string countOfAtoms(string formula) {
        formula += ')';
        stack<map<string, int>> s;
        s.push({});
        string e, cnt, ans;

        for (const char& c: formula) {

            if (isdigit(c)) {
                cnt += c;
            } else {
                if (e.empty() && !cnt.empty()) {
                    for (auto& [k, v]: s.top())
                        v *= stoi(cnt);

                    cnt.clear();
                    auto temp = s.top();
                    s.pop();
                    for (auto& [k, v]: temp)
                        s.top()[k] += v;
                }

                if (!e.empty() && !islower(c)) {
                    s.top()[e] += cnt.empty() ? 1 : stoi(cnt);
                    e.clear();
                    cnt.clear();
                }

                if (c == '(') {
                    s.push({});
                } else if (c != ')') {
                    e += c;
                }
            }
        }

        for (const auto& [k, v]: s.top()) {
            ans += k;
            if (v != 1) ans += to_string(v);
        }

        return ans;
    }
};
