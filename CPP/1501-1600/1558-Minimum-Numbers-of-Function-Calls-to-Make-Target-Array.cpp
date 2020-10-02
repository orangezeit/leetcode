class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans(0);
        bool repeated;
        do {
            repeated = false;
            for (int& i: nums) {
                if (i % 2) {i--; ans++;}
                if (i /= 2) repeated = true;
            }
            if (repeated) ans++;
        } while (repeated);
        return ans;
    }
};
