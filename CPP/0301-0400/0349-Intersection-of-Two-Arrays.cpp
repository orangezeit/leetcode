    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2;
        
        for (int i = 0; i < nums2.size(); ++i) {
            if (s1.find(nums2[i]) != s1.end()) {
                s2.insert(nums2[i]);
            }
        }
        
        return vector<int>(s2.begin(), s2.end());
    }
