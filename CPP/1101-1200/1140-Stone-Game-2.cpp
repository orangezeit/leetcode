class Solution {
public:
    vector<vector<pair<int, int>>> dp1, dp2;

    pair<int, int> playGame(const vector<int>& piles, int curr, int maxPiles, bool player) {
        if (player) {
            if (dp1[curr][maxPiles].first || dp1[curr][maxPiles].second) return dp1[curr][maxPiles];
        } else {
            if (dp2[curr][maxPiles].first || dp2[curr][maxPiles].second) return dp2[curr][maxPiles];
        }
        int collect(0);
        pair<int, int> p = {0, 0};

        if (curr + 2 * maxPiles >= piles.size()) {
            for (int i = curr; i < piles.size(); ++i)
                collect += piles[i];
            if (player) {
                dp1[curr][maxPiles] = {collect, 0};
                return {collect, 0};
            } else {
                dp2[curr][maxPiles] = {0, collect};
                return {0, collect};
            }

        }

        for (int i = curr; i < curr + 2 * maxPiles; ++i) {
            collect += piles[i];
            int m = max(i + 1 - curr, maxPiles);
            auto temp = playGame(piles, i + 1, m, !player);
            player ? temp.first += collect : temp.second += collect;
            if (player) {
                if (p.first < temp.first) p = temp;
            } else {
                if (p.second < temp.second) p = temp;
            }
        }
        if (player) {
            dp1[curr][maxPiles] = p;
        } else {
            dp2[curr][maxPiles] = p;
        }
        return p;
    }

    int stoneGameII(vector<int>& piles) {
        dp1 = vector<vector<pair<int, int>>>(piles.size(), vector<pair<int, int>>(piles.size() + 1));
        dp2 = vector<vector<pair<int, int>>>(piles.size(), vector<pair<int, int>>(piles.size() + 1));
        pair<int, int> p = playGame(piles, 0, 1, true);
        return p.first;
    }
};
