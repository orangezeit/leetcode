class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<vector<int>> cnts(sideLength, vector<int>(sideLength));

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cnts[i % sideLength][j % sideLength]++;
            }
        }

        priority_queue<int> pq;
        for (const vector<int>& row: cnts)
            for (const int& n: row)
                pq.push(n);
        int ans(0);
        while (maxOnes--) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
