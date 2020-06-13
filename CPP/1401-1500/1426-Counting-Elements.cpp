class Solution {
public:
    int countElements(vector<int>& arr) {
        vector<int> cnts(1002);
        int ans(0);
        for (const int& i: arr) cnts[i]++;
        for (int i = 0; i <= 1000; ++i)
            if (cnts[i+1])
                ans += cnts[i];
        return ans;
    }
};
