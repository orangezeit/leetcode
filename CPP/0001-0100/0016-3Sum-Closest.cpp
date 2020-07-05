class Solution {
public:
    void sumHelper(vector<int> nums, int target, int& twoSum, int& diff) {

        int i = 0;
        int j = nums.size()-1;

        while (i < j) {

            if (abs(target-nums[i]-nums[j]) < diff) {
                diff = abs(target-nums[i]-nums[j]);
                twoSum = nums[i] + nums[j];
            }

            if (nums[i] + nums[j] == target) {
                break;
            } else if (nums[i] + nums[j] < target) {
                i++;
            } else {
                j--;
            }
        }
    }

    int threeSumClosest(vector<int>& nums, int target) {
        // Time Complexity: O(N^2)
        // Space Complexity: O(1)
        unordered_set<int> targets;

        sort(nums.begin(), nums.end());

        int k, twoSum;
        int threeSum = nums[0] + nums[1] + nums[2];
        int diff = abs(threeSum-target);
        int mindiff = diff;

        for (int i = 0; i < nums.size(); ++i) {
            k = nums[i];

            if (targets.find(k) == targets.end()) {
                targets.insert(k);
                nums.erase(nums.begin()+i);

                sumHelper(nums, target-k, twoSum, diff);

                if (mindiff > diff) {
                    mindiff = diff;
                    threeSum = twoSum + k;
                }
                nums.insert(nums.begin()+i, k);
            }

        }

        return threeSum;
    }
};
