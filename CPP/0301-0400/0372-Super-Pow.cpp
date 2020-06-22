class Solution {
public:
    int superPow(int a, vector<int>& b) {
        a = a % 1337;
        int t = a;
        //a = 1;

        unordered_set<int> mods;
        vector<int> infos(1337);

        int k = 0;

        while (mods.find(a) == mods.end()) {
            mods.insert(a);
            infos[k] = a;
            a = (a * t) % 1337;
            k++;
        }

        int c = mods.size();
        //cout << c << endl;
        int res, digit;
        int total = 0;

        for (int i = 0; i < b.size(); ++i) {
            digit = b.size()-i-1;
            res = b[i];
            if (res != 0) {
                while (digit > 0) {
                    res = (res * 10) % c;
                    digit--;
                }
            }
            total = (total + res) % c;

        }
        if (total == 0) {
            return 1;
        } else {
            return infos[total-1];
        }

    }
};
