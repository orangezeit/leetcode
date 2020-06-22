class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i, j, k, left(-1000), middle(-1000), right(-1000);

        if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2) {
            return false;
        }

        if (nums[0] < nums[1] && nums[1] < nums[2]) {
            return true;
        } else if (/*nums[0] < nums[1] && */nums[0] < nums[2]) {
            left = nums[0];
            middle = nums[2];
        } else if (nums[1] < nums[2]) {
            left = nums[1];
            middle = nums[2];
        } else {
            left = nums[2];
        }
        //cout << left << " " << middle << " " << right << endl;

        if (nums.size() != 3) {
            for (i = 3; i < nums.size(); ++i) {
                if (middle == -1000 && right == -1000) {
                    //cout << "a" << endl;
                    if (left < nums[i]) {
                        middle = nums[i];
                    } else {
                        left = nums[i];
                    }
                } else {
                    if (nums[i] > middle) {
                        return true;
                    } else if (nums[i] <= middle && nums[i] > left) {
                        middle = nums[i];
                    }
                }
                //cout << left << " " << middle << " " << right << endl;
            }
        }
        return false;
    }
};
