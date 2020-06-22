class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int k1(candies.size());

        sort(candies.begin(), candies.end());
        candies.resize(distance(candies.begin(), unique(candies.begin(), candies.end())));
        int k2(candies.size());

        return min(k1 / 2, k2);
    }
};
