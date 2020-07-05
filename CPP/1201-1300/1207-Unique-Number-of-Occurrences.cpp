class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnts;
        unordered_set<int> rec;

        for (const int& n: arr) cnts[n]++;
        for (const auto& [k, v]: cnts) {
            if (!rec.insert(v).second)
                return false;
        }
        return true;
    }
};
