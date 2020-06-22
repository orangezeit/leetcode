class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> rec;
        priority_queue<pair<int, int>> pq;
        vector<int> ans(k);
        int n(0);

        for (int i = 0; i < nums.size(); ++i)
            rec[nums[i]]++;

        for (auto it = rec.begin(); it != rec.end(); ++it)
            pq.push({it->second, it->first});

        while (n < k) {
            ans[n++] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};
