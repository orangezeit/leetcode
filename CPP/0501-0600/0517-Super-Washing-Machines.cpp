class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int s(accumulate(machines.begin(), machines.end(), 0));
        if (s % machines.size()) return -1;
        int pivot(s / machines.size()), pre(0), res(0);

        for (int m: machines) {
            int temp = pre;
            pre += m - pivot;
            if (pre > 0 && temp < 0)
                res = max(res, m - pivot);
            res = max(res, abs(pre));
        }

        return res;
    }
};
