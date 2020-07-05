class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int delta = tomatoSlices - cheeseSlices * 2;
        if (delta % 2 || delta < 0 || cheeseSlices - delta / 2 < 0) return {};
        return {delta / 2, cheeseSlices - delta / 2};


    }
};
