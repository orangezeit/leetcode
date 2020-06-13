class Solution {
public:
    unordered_map<int, vector<vector<int>>> rec;
    const vector<vector<int>> combineFactors(const vector<vector<int>>& va, const vector<vector<int>>& vb) {
        vector<vector<int>> ans;
        
        for (const vector<int>& a: va) {
            for (const vector<int>& b: vb) {
                if (a.back() > b.front()) continue;
                vector<int> v;
                v.reserve(a.size() + b.size());
                v.insert(v.end(), a.begin(), a.end());
                v.insert(v.end(), b.begin(), b.end());
                ans.push_back(v);
            }
        }
        
        return ans;
    }
    
    const vector<vector<int>> helper(int n) {
        if (rec.count(n)) return rec[n];
        
        vector<vector<int>> factors({{n}});
        
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                vector<vector<int>> t = combineFactors(helper(i), helper(n / i));
                factors.insert(factors.end(), t.begin(), t.end());
            }
        }
        sort(factors.begin(), factors.end());
        factors.resize(distance(factors.begin(), unique(factors.begin(), factors.end())));
        return rec[n] = factors;
    }
    
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans = helper(n);
        ans.pop_back();
        return ans;
    }
};
