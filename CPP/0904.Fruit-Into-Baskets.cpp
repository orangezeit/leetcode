class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> rec;
        int k(0), len(0);
        for (int i = 0; i < tree.size(); ++i) {
            rec[tree[i]]++;
            while (rec.size() > 2) {
                if (--rec[tree[k]] == 0) rec.erase(tree[k]);
                k++;
            }
            len = max(len, i - k + 1);
        }
        return len;
    }
};
