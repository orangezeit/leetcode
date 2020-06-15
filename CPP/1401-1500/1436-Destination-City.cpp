class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> roadmap;

        for (const vector<string>& path: paths)
            roadmap[path[0]] = path[1];

        string city(paths[0][1]);
        while (roadmap.count(city))
            city = roadmap[city];

        return city;
    }
};
