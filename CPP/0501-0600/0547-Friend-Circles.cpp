
class Solution {
public:
    int find(int i, vector<int>& parents) {
        if (i != parents[i])
            parents[i] = find(parents[i], parents);
        return parents[i];
    }

    void unite(int i, int j, vector<int>& parents) {
        int pi = find(i, parents);
        int pj = find(j, parents);

        if (pi != pj)
            parents[pj] = pi;
    }

    int findCircleNum(vector<vector<int>>& M) {
        vector<int> parents(M.size());

        for (int i = 0; i < M.size(); ++i)
            parents[i] = i;

        for (int i = 0; i < M.size(); ++i)
            for (int j = i; j < M.size(); ++j)
                if (M[i][j])
                    unite(i, j, parents);

        for (int i = 0; i < M.size(); ++i)
            find(i, parents);

        unordered_set<int> res(parents.begin(), parents.end());

        return res.size();
    }
};
