class Solution {
public:
    unordered_set<int> visited;
    void dfs(int curr, int& c, vector<int>& status, vector<int>& candies, const vector<vector<int>>& keys, const vector<vector<int>>& containedBoxes) {

        if (status[curr] == 0) return;
        if (visited.count(curr)) return;

        //c += candies[curr];
        visited.insert(curr);

        for (int key: keys[curr]) status[key] = 1;

        while (true) {
            //int temp(c);
            vector<int> copy_sta(status);
            for (int nb: containedBoxes[curr]) {
                dfs(nb, c, status, candies, keys, containedBoxes);
            }
            if (copy_sta == status) break;
            //if (temp == c) break;
        }

    }

    void dfs2(int curr, int&c, vector<int>& status, vector<int>& candies, const vector<vector<int>>& keys, const vector<vector<int>>& containedBoxes) {
        if (status[curr] == 0) return;
        if (visited.count(curr)) return;

        c += candies[curr];
        visited.insert(curr);


        for (int nb: containedBoxes[curr]) {
                dfs2(nb, c, status, candies, keys, containedBoxes);
            }
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int c(0);
        for (int b: initialBoxes) {
            dfs(b, c, status, candies, keys, containedBoxes);
        }
        visited.clear();
        for (int b: initialBoxes) {
            dfs2(b, c, status, candies, keys, containedBoxes);
        }
        return c;
    }
};
