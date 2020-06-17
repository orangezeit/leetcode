class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        // method 1: brute force O(n^3)
        //int c = 0;
        /*
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i; j < A.size(); ++j) {
                int sum = 0;

                for (int k = i; k <= j; ++k) {
                    sum += A[k];
                }

                if (sum == S) c++;
            }
        }

        return c;
        */

        // method 2: O(n^2), improved
        /*
        for (int i = 0; i < A.size(); ++i) {
            int sum = 0;

            for (int j = i; j < A.size(); ++j) {

                sum += A[j];
                if (sum == S) {
                    c++;
                } else if (sum > S) {
                    break;
                }
            }

            if (sum < S) break;
        }

        */

        // method 3: O(n)

        vector<int> ones;

        ones.push_back(-1);

        for (int i = 0; i < A.size(); ++i)
            if (A[i])
                ones.push_back(i);

        ones.push_back(A.size());

        if (ones.size()-2 < S)
            return 0;

        int sum = 0;

        if (S == 0) {
            for (int i = 1; i < ones.size(); ++i) {
                sum += (ones[i] - ones[i-1]) * (ones[i] - ones[i-1] - 1) / 2;
            }
        } else {
            for (int i = 1; i < ones.size() - S; ++i) {
                sum += (ones[i] - ones[i-1]) * (ones[i+S] - ones[i+S-1]);
            }
        }

        return sum;
    }
};
