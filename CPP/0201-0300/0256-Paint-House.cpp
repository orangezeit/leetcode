class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int red(0), blue(0), green(0);
        
        for (const vector<int>& cost: costs) {
            int new_red = cost[0] + min(blue, green);
            int new_blue = cost[1] + min(red, green);
            int new_green = cost[2] + min(red, blue);
            red = new_red;
            blue = new_blue;
            green = new_green;
        }
        
        return min(red, min(blue, green));
    }
};
