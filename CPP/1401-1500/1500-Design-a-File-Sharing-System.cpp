class FileSharing {
public:
    vector<set<int>> files;
    unordered_map<int, vector<int>> users;
    int id = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    FileSharing(int m) : files(m + 1) {}

    int join(vector<int> oc) {
        int uid;
        if (pq.empty()) uid = ++id;
        else {
            uid = pq.top();
            pq.pop();
        }

        for (const int& c: oc)
            files[c].insert(uid);
        users[uid] = oc;
        return uid;
    }

    void leave(int userID) {
        if (!users.count(userID)) return;

        for (const int& f: users[userID])
            files[f].erase(userID);

        users.erase(userID);
        pq.push(userID);
    }

    vector<int> request(int userID, int chunkID) {
        if (!users.count(userID)) return {};
        vector<int> ans(files[chunkID].begin(), files[chunkID].end());
        if (!ans.empty() && !files[chunkID].count(userID)) {
            files[chunkID].insert(userID);
            users[userID].emplace_back(chunkID);
        }
        return ans;
    }
};

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing* obj = new FileSharing(m);
 * int param_1 = obj->join(ownedChunks);
 * obj->leave(userID);
 * vector<int> param_3 = obj->request(userID,chunkID);
 */
