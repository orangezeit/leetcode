class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> cnts;
        for (const int& i: target) cnts[i]++;
        for (const int& i: arr) cnts[i]--;
        for (const auto&[k, v]: cnts)
            if (v)
                return false;
        return true;
    }
};
