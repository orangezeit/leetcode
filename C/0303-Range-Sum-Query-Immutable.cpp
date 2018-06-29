private:
    map<int, int> record;
public:
    NumArray(vector<int> nums) {
        if (!nums.empty()) {
            record[0] = nums[0];
        }
        
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1];
            record[i] = nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i) {
            return record[j] - record[i-1];
        } else {
            return record[j];
        }
    }
