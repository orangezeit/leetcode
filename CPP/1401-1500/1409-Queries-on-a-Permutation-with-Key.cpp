class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        unordered_map<int, int> mp;
        vector<int> arr(m), ans;
        for (int i = 1; i <= m; ++i) {
            arr[i-1] = i;
            mp[i] = i-1;
        }
        for (int q: queries) {
            ans.push_back(mp[q]);
            // modify
            int x = mp[q];
            arr.erase(arr.begin() + mp[q]);
            arr.insert(arr.begin(), q);
            for (int i = 0; i <= x; ++i)
                mp[arr[i]] = i;
        }
        return ans;
    }
};
