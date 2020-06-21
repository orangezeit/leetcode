class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int n(a.size()), cnt(0);
        vector<int> b(a);
        sort(b.begin(), b.end());

        unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i) {
            if (!(++mp[a[i]])) mp.erase(a[i]);
            if (!(--mp[b[i]])) mp.erase(b[i]);
            if (mp.empty()) cnt++;
        }

        return cnt;
    }
};
