class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> groups;
        for (const int& d: deck) groups[d]++;

        int x(0);
        for (const auto& [k, v]: groups) x = gcd(x, v);

        return x >= 2;
    }
};
