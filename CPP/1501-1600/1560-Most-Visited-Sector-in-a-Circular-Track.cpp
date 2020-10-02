class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> sectors(n + 1), ans;
        sectors[rounds[0]]++;
        for (int i = 1; i < rounds.size(); ++i) {
            int r = rounds[i] + (rounds[i] <= rounds[i - 1] ? n : 0);
            for (int j = rounds[i - 1]; j < r; ++j)
                sectors[j % n + 1]++;
        }
        int e = *max_element(sectors.begin(), sectors.end());
        for (int i = 1; i <= n; ++i)
            if (sectors[i] == e)
                ans.emplace_back(i);
        return ans;
    }
};
