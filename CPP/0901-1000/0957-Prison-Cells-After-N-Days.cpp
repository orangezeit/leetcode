class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int c(N);
        unordered_set<int> nums;
        vector<int> rec = {0};

        while (c--) {
            vector<int> newcells(8);
            int n(0);
            for (int i = 1; i <= 6; ++i) {
                newcells[i] = cells[i-1] + cells[i+1] != 1;
                n += (newcells[i] << (i - 1));
            }
            if (nums.count(n)) break;
            else {
                nums.insert(n);
                rec.push_back(n);
            }
            swap(newcells, cells);
        }

        if (c < 0) return cells;
        rec[0] = rec.back();
        c = rec[N % (rec.size() - 1)];

        vector<int> ans(8);
        for (int i = 1; i <= 6; ++i) {
            ans[i] = c % 2;
            c /= 2;
        }
        return ans;
    }
};
