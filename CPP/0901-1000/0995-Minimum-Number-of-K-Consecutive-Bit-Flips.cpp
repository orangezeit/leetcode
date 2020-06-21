class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        bool flip = false;
        vector<bool> flipped(A.size());
        int res(0);

        for (int i = 0; i < A.size(); ++i) {
            if (i >= K) flip ^= flipped[i - K];
            if (!(A[i] ^ flip)) {
                if (i + K > A.size()) return -1;
                flipped[i] = true;
                flip = !flip;
                ++res;
            }
        }

        return res;
    }
};
