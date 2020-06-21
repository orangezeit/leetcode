class Solution {
public:
    map<vector<int>, int> rec;

    int shoppingOffers(const vector<int>& price, const vector<vector<int>>& special, vector<int>& needs) {
        if (rec.count(needs)) return rec[needs];

        int costs(0);

        for (int i = 0; i < needs.size(); ++i)
            costs += needs[i] * price[i];

        for (const vector<int>& spec: special) {
            bool test(true);
            for (int i = 0; i < needs.size(); ++i) {
                if (spec[i] > needs[i]) {
                    test = false;
                    break;
                }
            }

            if (test) {
                for (int i = 0; i < needs.size(); ++i)
                    needs[i] -= spec[i];
                costs = min(costs, spec.back() + shoppingOffers(price, special, needs));
                for (int i = 0; i < needs.size(); ++i)
                    needs[i] += spec[i];
            }
        }

        return rec[needs] = costs;
    }
};
