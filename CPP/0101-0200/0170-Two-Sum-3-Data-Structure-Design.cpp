class TwoSum {
private:
    unordered_set<int> nums, repeated;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int n) {
        nums.count(n) ? repeated.insert(n) : nums.insert(n);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int v) {
        for (const int& i: nums) {
            if (2 * i == v) {
                if (repeated.count(i)) return true;
            } else {
                if (nums.count(v - i)) return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
