class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> heads(n, true);
        vector<int> ans;
        for (const vector<int>& edge: edges)
            heads[edge[1]] = false;
        for (int i = 0; i < n; ++i)
            if (heads[i])
                ans.emplace_back(i);
        return ans;
    }
};
