class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> seq;
        set<vector<int>> seqs;

        function<void(int)> dfs = [&](int k) {
            for (int i = k; i < nums.size(); ++i) {
                if (!seq.empty() && seq.back() > nums[i]) continue;
                seq.push_back(nums[i]);
                dfs(i + 1);
                seq.pop_back();
            }

            if (seq.size() >= 2) seqs.insert(seq);
        };

        dfs(0);

        return vector<vector<int>>(seqs.begin(), seqs.end());
    }
};
