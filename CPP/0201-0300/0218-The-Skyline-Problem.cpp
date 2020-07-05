class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        map<int, priority_queue<int>> line;

        for (vector<int>& bldg: buildings) {
            line[bldg[0]].push(bldg[2]);
            line[bldg[1]].push(-bldg[2]);
        }

        map<int, int> skyline;
        vector<vector<int>> ans;

        for (auto& [k, pq]: line) {
            while (!pq.empty()) {
                if (pq.top() > 0)
                    skyline[pq.top()]++;
                else if (!(--skyline[-pq.top()]))
                    skyline.erase(-pq.top());
                pq.pop();
            }

            if (skyline.empty())
                ans.push_back({k, 0});
            else if (ans.empty() || ans.back().back() != skyline.rbegin()->first)
                ans.push_back({k, skyline.rbegin()->first});
        }

        return ans;
    }
};
