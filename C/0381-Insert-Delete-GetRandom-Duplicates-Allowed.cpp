private:
    unordered_map<int, vector<int>> hashmap;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if (hashmap.find(val) == hashmap.end()) {
            nums.push_back(val);
            hashmap[val].push_back(nums.size()-1);
            return true;
        } else {
            nums.push_back(val);
            hashmap[val].push_back(nums.size()-1);
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (hashmap.find(val) != hashmap.end()) {
            
            hashmap[nums.back()].back() = hashmap[val].back();
            //sort(hashmap[nums.back()].begin(), hashmap[nums.back()].end());
            // In this case, we can sort with time complexity O(n).
            if (hashmap[nums.back()].size() > 1) {
                for (int i = hashmap[nums.back()].size() - 1; i >= 1; --i) {
                    if (hashmap[nums.back()][i-1] > hashmap[nums.back()][i]) {
                        swap(hashmap[nums.back()][i-1], hashmap[nums.back()][i]);
                    } else {
                        break;
                    }
                }
            }
            swap(nums[hashmap[val].back()], nums.back());
            nums.pop_back();
            hashmap[val].pop_back();
            if (hashmap[val].empty()) {
                hashmap.erase(val);
            }
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
