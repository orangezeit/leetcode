class Solution {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int, int> cnts;
        int ans(0);
        for (const int& i: A)
            for (const int& j: A)
                cnts[i & j]++;

        for (const int& i: A)
            for (const auto& [k, v]: cnts)
                if (!(k & i))
                    ans += v;
        return ans;
    }
};
