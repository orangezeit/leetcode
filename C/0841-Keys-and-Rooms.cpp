private:
    unordered_set<int> visited;
public:
    void visit(vector<vector<int>> rooms) {
        int k(visited.size());
            
        for (auto it = visited.begin(); it != visited.end(); ++it) {
            if (!rooms[*it].empty()) {
                for (int i = 0; i < rooms[*it].size(); ++i) {
                    visited.insert(rooms[*it][i]);
                }
            }
        }
            
        if (k == visited.size()) {
            return;
        }
            
        visit(rooms);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.insert(0);
        visit(rooms);
        return visited.size() == rooms.size();
    }
