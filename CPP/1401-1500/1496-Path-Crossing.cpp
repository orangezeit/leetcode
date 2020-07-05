class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int, int> xy = {0, 0};
        set<pair<int, int>> visited({{0, 0}});
        unordered_map<char, pair<int, int>> mp = {{'N', {0, 1}}, {'S', {0, -1}}, {'W', {-1, 0}}, {'E', {1, 0}}};
        for (const char& d: path) {
            auto ij = mp[d];
            xy.first += ij.first;
            xy.second += ij.second;
            if (visited.count(xy)) return true;
            visited.insert(xy);
        }
        return false;
    }
};
