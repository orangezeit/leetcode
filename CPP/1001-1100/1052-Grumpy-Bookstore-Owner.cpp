class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int x) {
        int s(0), window(0), n(customers.size());
        for (int i = 0; i < n; ++i)
            if (grumpy[i] - 1)
                s += customers[i];
        for (int i = 0; i < x; ++i)
            if (grumpy[i])
                window += customers[i];
        int magic(window);
        for (int i = x; i < n; ++i)
            magic = max(magic, window += (grumpy[i] ? customers[i] : 0) - (grumpy[i - x] ? customers[i - x] : 0));
        return s + magic;
    }
};
