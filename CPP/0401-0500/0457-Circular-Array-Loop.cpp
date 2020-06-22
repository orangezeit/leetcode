class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        unordered_set<int> hashset;
        int n = nums.size();
        int k;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                while (nums[i] <= 0) {
                    nums[i] += n;
                }
                nums[i] -= n;
            } else {
                nums[i] = nums[i] % n;
            }

        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                k = i;
                if (nums[k] > 0) {
                    while (nums[k] > 0) {
                        if (hashset.find(k) == hashset.end()) {
                            hashset.insert(k);
                        } else {
                            return true;
                        }

                        k = (k + nums[k]) % n;
                    }

                } else {
                    while (nums[k] < 0) {
                        if (hashset.find(k) == hashset.end()) {
                            hashset.insert(k);
                        } else {
                            return true;
                        }

                        k = (k + n + nums[k]) % n;
                    }

                }


                for (auto it = hashset.begin(); it != hashset.end(); ++it) {
                    nums[*it] = 0;
                }
                hashset.clear();
            }
        }
        return false;
    }
};
