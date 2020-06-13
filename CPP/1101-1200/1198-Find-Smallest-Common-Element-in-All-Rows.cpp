class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int, int> rec;
        for (const vector<int>& row: mat)
            for (const int& num: row)
                if (++rec[num] == mat.size())
                    return num;
        return -1;
    }
};
