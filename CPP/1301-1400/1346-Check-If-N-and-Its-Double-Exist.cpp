class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (const int& i: arr) {
            if (s.count(2 * i) || i % 2 == 0 && s.count(i / 2))
                return true;
            s.insert(i);
        }
        return false;
    }
};
