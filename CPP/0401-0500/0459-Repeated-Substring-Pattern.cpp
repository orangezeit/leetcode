class Solution {
public:

    bool repeatedSubstringPattern(string s) {
        if (s.length() == 0 || s.length() == 1) {
            return false;
        }

        vector<int> factors;
        string sub;
        int i, k;

        for (i = 1; i <= s.length()-1; ++i) {
            if (s.length() % i == 0) {
                factors.push_back(i);
            }
        }

        for (i = factors.size()-1; i >=0; --i) {
            //cout << factors[i] << endl;
            if (factors[i] != 0) {
            k = factors[i];
            sub = s.substr(0, k);

            while (k < s.length()) {
                if (sub != s.substr(k, factors[i])) {
                    break;
                } else {
                    k = k + factors[i];
                }
            }

            if (k == s.length()) {
                return true;
            } else {
                for (int j = 1; j < factors.size(); ++j) {
                    if (factors[j] != 0) {
                        if (factors[i] % factors[j] == 0) {
                            factors[j] = 0;
                        }
                    }
                }
            }
            }
        }
        return false;
    }
};
