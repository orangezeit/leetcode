class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> garden(n);

        for (const vector<int>& p: paths) {
            garden[p[0] - 1].emplace_back(p[1] - 1);
            garden[p[1] - 1].emplace_back(p[0] - 1);
        }

        vector<int> res(n);

        for (int i = 0; i < n; ++i) {
            int k(0), candidates[4] = {1, 2, 3, 4};

            for (const int& e: garden[i])
                if (res[e]) candidates[res[e] - 1] = 0;

            while (!candidates[k++]) {}
            res[i] = k;
        }

        return res;
    }
};
