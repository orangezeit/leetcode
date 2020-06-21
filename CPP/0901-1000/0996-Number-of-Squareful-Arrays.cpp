class Solution {
public:

    bool isSquare(int x) {
        return (int)sqrt(x) * (int)sqrt(x) == x;
    }

    int dfs(vector<int>& path, vector<int>& A, unordered_map<int, int>& cnts) {
        if (path.size() == A.size()) return 1;

        int total(0);
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == -1) continue;
            if (i && A[i] == A[i-1]) continue;
            if (!cnts[A[i]]) continue;
            if (!path.empty() && !isSquare(path.back() + A[i])) continue;

            path.push_back(A[i]);
            cnts[A[i]]--;
            A[i] = -1;
            total += dfs(path, A, cnts);
            A[i] = path.back();
            path.pop_back();
            cnts[A[i]]++;
        }

        return total;
    }

    int numSquarefulPerms(vector<int>& A) {
        //unordered_map<int, unordered_set<int>> rec(A.size());
        unordered_map<int, int> cnts;
        vector<int> path;
        sort(A.begin(), A.end());

        for (int i = 0; i < A.size(); ++i)
            cnts[A[i]]++;

        return dfs(path, A, cnts);
    }
};
