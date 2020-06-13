class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int len(0);
        int left(0);
        int zeros(0);

        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == 0) zeros++;
            while (zeros > K) {
                if (A[left++] == 0)
                    zeros--;
            }
            len = max(len, i - left + 1);
        }

        return len;
    }

    int findMaxConsecutiveOnes(vector<int>& nums) {
        return longestOnes(nums, 1);
    }
};
