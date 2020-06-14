class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {

        int minDiff = height + width;
        int sum(0); // sum of tnt

        for (int i = 0; i < nuts.size(); ++i) {
            int sn = abs(squirrel[0] - nuts[i][0]) + abs(squirrel[1] - nuts[i][1]);
            int tn = abs(nuts[i][0] - tree[0]) + abs(nuts[i][1] - tree[1]);
            //cout << sn << " " << tn << endl;
            minDiff = min(minDiff, sn - tn);
            sum += tn * 2;
        }
        //cout << minDiff << endl;
        return sum + minDiff;
    }
};
