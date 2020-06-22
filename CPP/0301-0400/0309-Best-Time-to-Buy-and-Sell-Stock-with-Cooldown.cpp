class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rest(0), sold(0), hold(INT_MIN);
        for (const int& p: prices) {
            int new_rest = max(rest, sold);
            int new_sold = hold + p;
            int new_hold = max(hold, rest - p);
            rest = new_rest;
            sold = new_sold;
            hold = new_hold;
        }

        return max(rest, sold);
    }
};
