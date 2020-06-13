class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int lower(0);
        int v(0);
        vector<int> ds(prices.size(), 0);

        for (int i = 0; i < prices.size(); ++i) {
            int decimal = stoi(prices[i].substr(prices[i].length() - 3, 3));
            int integer = stoi(prices[i].substr(0, prices[i].length() - 4));
            //cout << integer << " " << decimal << endl;
            if (decimal) v++;
            lower += integer;
            ds[i] = decimal;
        }
        //target *= 1000;
        int re(0);

        if (target >= lower && target <= lower + v) {
            sort(ds.begin(), ds.end());
            int rd = lower + v - target;
            for (int i = 0; i < ds.size(); ++i) {
                if (ds[i] == 0) continue;
                else {
                    if (rd) {
                        re += ds[i];
                        rd--;
                    } else {
                        re += (1000 - ds[i]);
                    }
                }
            }
            string ans = to_string(re);
            while (ans.length() < 4) ans.insert(ans.begin(), '0');
            ans.insert(ans.end() - 3, '.');
            return ans;
        } else {
            return "-1";
        }
    }
};
