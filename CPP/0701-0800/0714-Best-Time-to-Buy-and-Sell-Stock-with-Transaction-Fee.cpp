class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // initial states
        int rest(0), sold(0), hold(INT_MIN + 50000);
        for (const int& p: prices) {
            int new_rest = max(rest, sold);
            int new_sold = hold + p - fee;
            int new_hold = max(hold, max(rest, sold) - p);
            rest = new_rest;
            sold = new_sold;
            hold = new_hold;
        }

        return max(rest, sold);
    }
};
