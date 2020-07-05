class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odds(0), evens(0);
        for (const int& i: chips) {
            i % 2 ? odds++ : evens++;
        }
        return min(odds, evens);
    }
};
