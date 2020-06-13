class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> rec;

        for (int i = 0; i < items.size(); ++i) {
            rec[items[i][0]].push(items[i][1]);
            if (rec[items[i][0]].size() > 5)
                rec[items[i][0]].pop();
        }
        vector<vector<int>> ans(rec.size(), vector<int>(2, 0));
        int k = 0;
        for (auto it = rec.begin(); it != rec.end(); ++it) {
            ans[k][0] = it->first;
            while (!it->second.empty()) {
                ans[k][1] += it->second.top();
                it->second.pop();
            }
            ans[k++][1] /= 5;
            //k++;
        }
        return ans;
    }
};
