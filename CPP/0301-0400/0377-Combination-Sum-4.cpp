class Solution {
public:
    unordered_map<int, int> rec;

    int traverse(const vector<int>& nums, int t) {
        //cout << t << " " << i << " " << j << endl;
        if (t == 0) {
            return 1;
        } else {
            int c(0);
            for (int k = 0; k < nums.size(); ++k) {
                if (nums[k] > t) break;
                if (!rec.count(t - nums[k]))
                    rec[t - nums[k]] = traverse(nums, t - nums[k]);
                c += rec[t - nums[k]];
            }
            return c;
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return traverse(nums, target);
    }
};
