class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> record;
        int ans(0);

        for (int i = 0; i < A.size(); ++i) {
            A[i] = ((A[i] % K) + K) % K;
            if (i) {A[i] += A[i-1]; A[i] %= K;}
            if (A[i] == 0) ans++;
            if (record.find(A[i]) != record.end())
                ans += record[A[i]];
            record[A[i]]++;
        }

        return ans;
    }
};
