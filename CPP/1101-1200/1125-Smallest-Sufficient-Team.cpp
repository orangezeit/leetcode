class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n(1 << req_skills.size());
        vector<int> dp(n, INT_MAX / 2);
        vector<long> pt(n);
        dp[0] = 0;
        //cout <<
        unordered_map<string, int> skillset;

        for (int i = 0; i < req_skills.size(); ++i) {
            skillset[req_skills[i]] = i;
        }

        vector<int> nametag(people.size());
        int k = 0;

        for (const vector<string>& skills: people) {
            for (const string& skill: skills) {
                nametag[k] |= (1 << skillset[skill]);
            }
            k++;
        }
        //cout << "a";
        for (int i = 0; i < people.size(); ++i) {
            const int s = nametag[i];
            if (s == 0) continue;
            //cout << s << endl;
            for (int j = n - 1; j >= 0; --j) {
                if (dp[j] + 1 < dp[j|s]) {
                    dp[j|s] = dp[j] + 1;
                    pt[j|s] = pt[j] | ((long) 1 << i);
                }
            }
        }
        k = 0;
        vector<int> ans;
        while (pt.back()) {
            if (pt.back() % 2) ans.push_back(k);
            pt.back() /= 2;
            k++;
        }

        return ans;
    }
};
