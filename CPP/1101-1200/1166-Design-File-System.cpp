struct TrieNode {
    string name;
    int n;
    unordered_map<string, TrieNode*> subfiles;
    TrieNode (string p, int v): name(p), n(v), subfiles() {}
};

class FileSystem {
public:
    TrieNode* tn = new TrieNode("", -1);
    FileSystem() {

    }
    queue<string> processing(const string& path) {
        queue<string> q;
        string f;
        for (int i = 1; i < path.length(); ++i) {
            if (path[i] == '/') {
                q.push(f);
                f.clear();
            } else {
                f += path[i];
            }
        }
        return q;
    }
    bool createPath(string path, int value) {
        path += '/';
        queue<string> q = processing(path);
        TrieNode* temp = tn;

        while (q.size() > 1) {
            string file = q.front();
            q.pop();

            if (!temp->subfiles.count(file)) return false;
            temp = temp->subfiles[file];
        }

        if (temp->subfiles.count(q.front())) return false;
        temp->subfiles[q.front()] = new TrieNode(q.front(), value);
        return true;
    }

    int get(string path) {
        path += '/';
        queue<string> q = processing(path);
        TrieNode* temp = tn;

        while (!q.empty()) {
            string file = q.front();
            q.pop();
            if (!temp->subfiles.count(file)) return -1;
            temp = temp->subfiles[file];
        }

        return temp->n;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
