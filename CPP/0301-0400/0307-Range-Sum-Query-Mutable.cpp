class NumArray {
private:
    int n;
    vector<int> ns, tree;
public:
    void update_each(const int& k, const int& val) {
        for (int i = k; i <= n; i += i & (-i))
            tree[i] += val;
    }

    int read(const int& k) {
        int sum(0);
        for (int i = k; i > 0; i -= i & (-i))
            sum += tree[i];
        return sum;
    }

    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        n = nums.size();
        swap(ns, nums);
        tree.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            update_each(i, ns[i - 1]);
    }

    void update(int i, int val) {
        val -= ns[i++];
        update_each(i, val);
        ns[--i] += val;
    }

    int sumRange(int i, int j) {
        return read(j + 1) - read(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
