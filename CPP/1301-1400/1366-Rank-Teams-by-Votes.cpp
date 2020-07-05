class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string ans(votes[0]);
        const int n(votes[0].length());
        vector<vector<int>> ranks(26, vector<int>(n));

        for (const string& vote: votes)
            for (int i = 0; i < n; ++i)
                ranks[vote[i] - 'A'][i]++;

		sort(ans.begin(), ans.end(),
             [&](const char& x, const char& y){
                return ranks[x - 'A'] > ranks[y - 'A'] || (ranks[x - 'A'] == ranks[y - 'A'] && x < y);
                });
        return ans;
    }
};
