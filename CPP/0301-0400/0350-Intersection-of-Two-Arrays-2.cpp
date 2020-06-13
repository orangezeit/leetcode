    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        vector<int> res;
        
        for (int i = 0; i < nums1.size(); ++i) {
            hashmap[nums1[i]]++;
        }
        
        for (int i = 0; i < nums2.size(); ++i) {
            if (hashmap[nums2[i]]){
                res.push_back(nums2[i]);
                hashmap[nums2[i]]--;
            }
        }
        
        return res;
    }
