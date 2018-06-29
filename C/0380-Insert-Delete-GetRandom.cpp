private:
    unordered_map<int, int> hashmap;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hashmap.find(val) == hashmap.end()) {
            nums.push_back(val);
            hashmap[val] = nums.size()-1;
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hashmap.find(val) != hashmap.end()) {
            hashmap[nums.back()] = hashmap[val];
            swap(nums[hashmap[val]], nums.back());
            nums.pop_back();
            hashmap.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
