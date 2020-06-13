class Solution {
public:
    int smallestFactorization(int a) {
        if (a == 1)
            return 1;

        vector<int> pf(4, 0);

        while (a % 2 == 0) {
            a /= 2;
            pf[0]++;
        }

        while (a % 3 == 0) {
            a /= 3;
            pf[1]++;
        }

        while (a % 5 == 0) {
            a /= 5;
            pf[2]++;
        }

        while (a % 7 == 0) {
            a /= 7;
            pf[3]++;
        }

        if (a > 1)
            return 0;

        string ans = string(pf[2], '5') + string(pf[3], '7');

        ans += string(pf[0] / 3, '8');
        pf[0] %= 3;
        //cout << pf[0] << endl;
        ans += string(pf[1] / 2, '9');
        pf[1] %= 2;

        if (pf[1] && pf[0]) {
            ans += '6';
            pf[0]--;
            pf[1]--;
        }

        if (pf[0] == 1)
            ans += '2';
        else if (pf[0] == 2)
            ans += '4';
        //ans += string(pf[0], '2');
        ans += string(pf[1], '3');

        sort(ans.begin(), ans.end());
        //cout << ans;
        if (ans.length() >= 11)
            return 0;
        else if (ans.length() == 10 && ans > "2147483647")
            return 0;
        return stoi(ans);
    }
};
