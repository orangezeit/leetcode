class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() <= 2) {
            return false;
        }

        pair<int, int> lowhigh;
        bool lpd(false), hpd(false), lpe(false);
        vector<pair<int, int>> infos;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] <= nums[i]) {
                lpd = true;
            } else {
                hpd = true;
            }

            if (lpd) {
                if (lpe) {
                    lowhigh.second = nums[i];
                } else {
                    lowhigh.first = nums[i-1];
                    lowhigh.second = nums[i];
                    lpe = true;
                }
                lpd = false;
            }

            if (hpd) {
                if (lpe) {
                    infos.push_back(lowhigh);

                    lowhigh.first = nums[i];
                }

                hpd = false;
            }

            if (infos.size() != 0) {
                for (int j = 0; j < infos.size(); ++j) {
                    if (infos[j].first < nums[i] && infos[j].second > nums[i]) {
                        return true;
                    }
                }
            }

        }

        return false;
    }
};
