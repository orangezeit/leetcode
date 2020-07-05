class Solution {
public:
    vector<int> f(vector<int>& ds, vector<int> dgs) {
        int x(2);
        vector<int> ans;
        for (int d: dgs) {
            while (ds[d] && x) {
                ds[d]--;
                x--;
            }
        }
        return ans;
    }
    string largestMultipleOfThree(vector<int>& digits) {
        // mod 3: 0, 1, 2
        // 1, (1, 1), 2, (2, 2)
        vector<int> ds(10);
        int ones(0), twos(0);
        string ans;
        for (int d: digits) ds[d]++;
        for (int d: {1, 4, 7}) {
            ones += ds[d];
        }
        for (int d: {2, 5, 8}) {
            twos += ds[d];
        }
        int oe(ones), tw(twos);
        ones %= 3;
        twos %= 3;
        if (ones && twos) {
            ones--;
            twos--;
        }
        if (ones == 0 && twos == 1) {
            int ca = ds[2] ? 2 : ds[5] ? 5 : 8;
            ds[ca]--;
        } else if (ones == 0 && twos == 2) {
            //give up 1 in ones if possible

            int ca = ds[1] ? 1 : ds[4] ? 4 : ds[7] ? 7 : 0;
            //cout <<  ca << endl;
            if (!ca) {
                vector<int> can = f(ds, {2,5,8});
            } else {
                ds[ca]--;
            }
        } else if (ones == 1 && twos == 0) {
            int ca = ds[1] ? 1 : ds[4] ? 4 : 7;
            ds[ca]--;
        } else if (ones == 2 && twos == 0) {
            //give up 1 in twos if possible
            int ca = ds[2] ? 2 : ds[5] ? 5 : ds[8] ? 8 : 0;
            //cout << ca << endl;
            if (!ca) {
                vector<int> can = f(ds, {1,4,7});
            } else {
                ds[ca]--;
            }
        }
        for (int i = 9; i >= 0; i--) {
            //cout << ds[i] << endl;
            if (ds[i] == 0) continue;
            while (ds[i]--) {
                ans += '0' + i;
            }
        }
        while (!ans.empty() && ans[0] == '0' && ans.length() > 1) ans.erase(ans.begin());
        return ans;
    }
};
