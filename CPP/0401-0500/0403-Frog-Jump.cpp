class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int, set<int>> record;
        int arr[3] = {-1, 0, 1};

        for (int& i: stones) record[i];
        record[0].insert(0);

        for (auto& p: record) {
            for (int step: p.second) {
                for (int& i: arr) {
                    if (step + i > 0 && record.count(p.first + step + i)) {
                        record[p.first + step + i].insert(step + i);
                    }
                }
            }
        }

        return !record[stones.back()].empty();
    }
};
