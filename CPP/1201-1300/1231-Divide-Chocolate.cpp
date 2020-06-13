class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int i = 1;
        int j = 1e9 / (K ? K : 1);

        while (i < j) {
            int m = i + (j - i + 1) / 2;
            int cuts(0), sum(0);
            for (const int& s: sweetness) {
                if ((sum += s) >= m) {
                    sum = 0;
                    if (++cuts > K) break;
                }

            }
            cuts > K ? i = m : j = m - 1;
        }

        return i;
    }
};
