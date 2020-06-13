class PhoneDirectory {
private:
    unordered_set<int> nums;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i)
            nums.insert(i);
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (nums.empty()) return -1;
        int num = *nums.begin();
        nums.erase(num);
        return num;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return nums.find(number) != nums.end();
    }

    /** Recycle or release a number. */
    void release(int number) {
        nums.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
