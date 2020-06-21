class Solution {
public:
    int atMostK(vector<int>& A, int K) {
        unordered_map<int, int> counter;
        int i(0), sum(0);

        for (int j = 0; j < A.size(); ++j) {
            if (!counter[A[j]]++) K--;

            while (K < 0) {
                counter[A[i]]--;
                if (!counter[A[i++]]) K++;
            }

            sum += j - i + 1;
        }

        return sum;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostK(A, K) - atMostK(A, K - 1);
    }
};
