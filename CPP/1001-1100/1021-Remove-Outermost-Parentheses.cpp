class Solution {
public:
    string removeOuterParentheses(string S) {
        int k = 0;
        stack<int> idx;

        for (int i = 0; i < S.length(); ++i) {
            if (k == 0) idx.push(i);
            S[i] == '(' ? k++ : k--;
            if (k == 0) idx.push(i);
        }

        while (!idx.empty()) {
            S.erase(idx.top(), 1);
            idx.pop();
        }

        return S;
    }
};
