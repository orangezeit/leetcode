class Solution {
public:
    string reverseParentheses(string s) {

        stack<pair<deque<char>, bool>> st;
        bool flip(false);

        for (const char& c: s) {
            if (c == '(') {
                st.push({{}, flip});
                flip = !flip;
            } else if (c == ')') {
                deque<char> temp;
                bool sign = st.top().second;

                while (!st.empty() && st.top().second == sign) {
                    while (!st.top().first.empty()) {
                        if (st.top().second) {
                            temp.push_back(st.top().first.front());
                            st.top().first.pop_front();
                        } else {
                            temp.push_front(st.top().first.back());
                            st.top().first.pop_back();
                        }
                    }
                    st.pop();
                }
                st.push({temp, flip = !flip});
            } else {
                st.push({{c}, flip});
            }
        }
        string ans;

        while (!st.empty()) {
            while (!st.top().first.empty()) {
                ans += st.top().first.back();
                st.top().first.pop_back();
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
