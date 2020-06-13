class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        set<int> slots;
        int i(1);
        for (const int& b: bulbs) {
            slots.insert(b);
            auto it = slots.find(b);
            if (it != slots.begin() && *prev(it) == b - k - 1 ||
                next(it) != slots.end() && *next(it) == b + k + 1) return i;
            i++;
        }
        return -1;
    }
};
