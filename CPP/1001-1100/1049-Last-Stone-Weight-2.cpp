class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        set<int> s({0});
        for (const int& i: stones) {
            set<int> t;
            for (const int& j: s) {
                t.insert(j + i);
                t.insert(j - i);
            }
            swap(s, t);
        }
        return *s.lower_bound(0);
    }
};
