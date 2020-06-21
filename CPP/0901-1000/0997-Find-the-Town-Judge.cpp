class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusters(n, 1), trustees(n);

        for (const vector<int>& t: trust) {
            trusters[t[0] - 1] = 0;
            trustees[t[1] - 1]++;
        }

        for (int i = 0; i < n; ++i)
            if (trusters[i] && trustees[i] == n - 1)
                return i + 1;

        return -1;
    }
};
