class Solution {
private:
    vector<int> data;
public:
    Solution(vector<int> w) {
        data = w;
        for (int i = 1; i < data.size(); ++i) {
            data[i] += data[i-1];
        }
    }

    int pickIndex() {
        int r = rand() % data.back();

        if (r < data[0]) return 0;

        int i = 0;
        int j = data.size() - 1;

        while (j - i > 1) {
            int k = (i+j)/2;
            r < data[k] ? j = k : i = k;
        }

        return j;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
