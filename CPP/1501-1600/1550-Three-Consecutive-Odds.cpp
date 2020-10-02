class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) return false;
        for (int i = 1; i + 1 < arr.size(); ++i)
            if (arr[i - 1] % 2 && arr[i] % 2 && arr[i + 1] % 2)
                return true;
        return false;
    }
};
