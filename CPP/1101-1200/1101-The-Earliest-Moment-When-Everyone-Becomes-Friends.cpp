class Solution {
private:
    vector<int> ones;
    int find(int x) {
        if (x != ones[x])
            ones[x] = find(ones[x]);
        return ones[x];

    }
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) ones[px] = py;
    }
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        ones.resize(N);
        for (int i = 0; i < N; ++i) {
            ones[i] = i;
        }
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>&b){return a[0] < b[0];});
        for (int i = 0; i < logs.size(); ++i) {
            //cout << "a" << endl;
            unite(logs[i][1], logs[i][2]);
            int temp = find(0);
            for (int k = 0; k < N; ++k) {
                if (temp != find(k)) break;
                if (k == N - 1) return logs[i][0];
                //cout << find(k) << " ";
            }//cout << endl;
        }
        return -1;
    }
};
