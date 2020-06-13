class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> roadmap;

        for (const vector<string> r: regions) {
            for (int i = 1; i < r.size(); ++i) {
                roadmap[r[i]] = r[0];
            }

        }

        vector<string> path1({region1}), path2({region2});

        while (roadmap.count(region1)) {
            region1 = roadmap[region1];
            path1.push_back(region1);
        }

        while (roadmap.count(region2)) {
            region2 = roadmap[region2];
            path2.push_back(region2);
        }

        reverse(path1.begin(), path1.end());
        reverse(path2.begin(), path2.end());

        for (int i = 1; i < min(path1.size(), path2.size()); ++i) {
            if (path1[i] != path2[i])
                return path1[i - 1];
        }

        return path1.size() < path2.size() ? path1.back() : path2.back();
    }
};
