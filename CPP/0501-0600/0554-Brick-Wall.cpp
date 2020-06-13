    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> hashmap;
        
        for (int i = 0; i < wall.size(); ++i) {
            hashmap[wall[i][0]]++;
            for (int j = 0; j < wall[i].size()-1; ++j) {
                wall[i][j+1] = wall[i][j] + wall[i][j+1];
                hashmap[wall[i][j+1]]++;
            }
        }
        
        hashmap.erase(wall[0].back());
        int maxBreak = 0;
        
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it) {
            maxBreak = max(maxBreak, it->second);
        }
        
        return wall.size() - maxBreak;
    }
