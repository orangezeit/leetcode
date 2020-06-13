/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:

    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if (!sea.hasShips(topRight, bottomLeft)) return 0;
        if (topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1]) return 1;

        int midX = (topRight[0] + bottomLeft[0])/2;
        int midY = (topRight[1] + bottomLeft[1])/2;
        return countShips(sea, {midX, midY}, bottomLeft) +
            countShips(sea, topRight, {midX+1, midY+1}) +
            countShips(sea, {midX, topRight[1]}, {bottomLeft[0], midY+1}) +
            countShips(sea, {topRight[0], midY}, {midX+1, bottomLeft[1]});
    }
};
