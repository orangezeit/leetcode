class NumArray {
private:
    vector<int> ns;
    vector<int> fenwick;
    int lowbit(int x) { return x & (-x); }
public:
    NumArray(vector<int>& nums) {
        ns = nums;
        fenwick = vector<int>(nums.size(), 0);
        int i = 1;

        while(i-1 < nums.size()) {
            int k = i;
            while(k-1 < nums.size()) {
                fenwick[k-1] += nums[i-1];
                k += lowbit(k);
            }
            i++;
        }

        //for (int i = 0; i < nums.size(); ++i) cout << fenwick[i] << endl;
        //for (int i = 0; i < nums.size(); ++i) cout << ns[i] << endl;
    }

    void update(int i, int val) {
        i++;
        int adj = val - ns[i-1];
        ns[i-1] = val;
        while (i-1 < ns.size()) {
            fenwick[i-1] += adj;
            i += lowbit(i);
        }
    }

    int sum(int x) {
        int s = 0;
        while (x > 0) {
            s += fenwick[x-1];
            x -= lowbit(x);
        }
        return s;
    }

    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
