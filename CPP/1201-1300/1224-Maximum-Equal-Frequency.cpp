class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        map<int, int> freq, cnts;
        int ans(0), k(0);

        for (const int& n: nums) {

            if (cnts.count(freq[n]) && !(--cnts[freq[n]]))
                cnts.erase(freq[n]);

            cnts[++freq[n]]++;

            ++k;
            if (cnts.size() == 1) {
                ans = k - 1;
                if (cnts.count(1)) ans = k;
            } else if (cnts.size() == 2) {
                if (cnts.count(1) && cnts[1] == 1)
                    ans = k;
                else {
                    auto it = cnts.begin(), jt(next(it));

                    if (jt->first - it->first == 1 && jt->second == 1) {
                        ans = k;
                    }

                }

            }

        }


        return freq.size() == 1 && freq.count(1) ? ans + 1 : ans;
    }
};
