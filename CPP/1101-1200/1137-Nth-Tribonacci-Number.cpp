class Solution {
public:
    int tribonacci(int n) {
        vector<long> res = {0, 1, 1};
        int k = 0;
        n -= 2;
        if (n <= 0) return res[n+2];
        while (n--) {
            res[k%3] += res[(k+1)%3] + res[(k+2)%3];
            k++;
        }
        return res[(k-1)%3];
    }
};
