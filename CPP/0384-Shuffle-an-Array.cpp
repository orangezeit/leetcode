private:
    vector<int> nums_copy;
    vector<int> curr;
public:
    Solution(vector<int> nums) {
        nums_copy = nums;
        curr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_copy;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (curr.size() != 0) {
            swap(curr[rand() % curr.size()], curr[rand() % curr.size()]);
        }
        
        return curr;
    }
