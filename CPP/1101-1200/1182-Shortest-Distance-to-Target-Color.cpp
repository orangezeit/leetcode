class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<set<int>> rec(3);

        for (int i = 0; i < colors.size(); ++i)
            rec[colors[i] - 1].insert(i);

        vector<int> ans(queries.size(), -1);
        int k(0);

        for (const vector<int>& query: queries) {
            //set<int> s = rec[query[1] - 1];
            if (rec[query[1] - 1].empty()) {
                //ans[k++] = -1;
                k++;
                continue;
            }
            auto i = rec[query[1] - 1].lower_bound(query[0]);
            if (i == rec[query[1] - 1].begin()) {
                //cout << "start" << "*" << *i << " " << query[0] << " " << *i - query[0] << endl;
                ans[k++] = (int)*i - query[0];
                //cout << k-1 << " " << ans[k-1] << endl;
            } else if (i == rec[query[1] - 1].end()) {
                ans[k++] = query[0] - (int)*(--i);
                //cout << k-1 << " " << ans[k-1] << endl;
            } else {
                int a = *i - query[0];
                int b = query[0] - *(--i);
                //cout << "a" << a << "b" << b << endl;
                ans[k++] = min(a, b);
                //cout << k-1 << " " << ans[k-1] << endl;
            }
        }

        return ans;
    }
};
