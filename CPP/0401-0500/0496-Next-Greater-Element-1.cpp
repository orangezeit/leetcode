class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        //int temp;
        vector<int> greater(findNums.size(), -1);

        for (int i = 0; i < findNums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (findNums[i] == nums[j]) {
                    if (j != nums.size()-1) {
                        for (int k = j; k <nums.size(); ++k) {
                            if(findNums[i] < nums[k]) {
                                greater[i] = nums[k];
                                break;
                            }
                        }
                    }
                    break;
                }
            }


        }

        return greater;
    }
};
