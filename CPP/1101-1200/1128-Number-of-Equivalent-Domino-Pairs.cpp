class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> m;
        int ans(0);

        for (int i = 0; i < dominoes.size(); ++i) {
            if (dominoes[i][0] > dominoes[i][1])
                swap(dominoes[i][0], dominoes[i][1]);
            m[dominoes[i][0] * 10 + dominoes[i][1]]++;
        }

        for (auto it = m.begin(); it != m.end(); ++it)
            ans += (it->second) * (it->second - 1);

        return ans / 2;
    }
};
