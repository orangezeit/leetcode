class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        char c[5] = {'0', '1', '6', '8', '9'};
        char d[5] = {'0', '1', '9', '8', '6'};
        string str(n, ' ');
        vector<string> ans;
        
        function<void(int)> dfs = [&](int curr) {
            if (curr == n / 2 + n % 2) {
                ans.push_back(str);
                return;
            } else {
                for (int i = (curr == 0 && n > 1); i < 5; ++i) {
                    if (curr == n / 2 && n % 2 && (i == 2 || i == 4)) continue;
                    str[curr] = c[i];
                    str[n - curr - 1] = d[i];
                    dfs(curr + 1);
                }
            }
        };
        
        dfs(0);
        return ans;
    }
};
