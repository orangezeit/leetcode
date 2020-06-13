class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<int> sums(nodes, 1);
        int ans(0);

        for (int i = nodes - 1; i >= 1; --i) {
            value[parent[i]] += value[i];
            sums[parent[i]] += value[i] ? sums[i] : 0;
        }

        return sums[0];
    }
};
