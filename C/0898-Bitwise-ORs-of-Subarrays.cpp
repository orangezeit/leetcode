    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> cur;
        unordered_set<int> nxt;
        unordered_set<int> ans;
        
        for (int i = 0; i < A.size(); ++i) {
            nxt.clear();
            nxt.insert(A[i]);
            for (int j : cur) {
                nxt.insert(A[i] | j);
            }
            
            cur.swap(nxt);
            ans.insert(cur.begin(), cur.end());
        }
        
        return ans.size();
    }
