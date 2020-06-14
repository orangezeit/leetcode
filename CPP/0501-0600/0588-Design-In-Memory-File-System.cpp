struct folder {
    string contents;
    unordered_map<string, folder*> subFolders;
};

class FileSystem {
public:
    folder* fd = new folder();

    vector<string> parsePath(string& path) {
        path += '/';
        int k(0);
        vector<string> res;

        for (int i = 0; i < path.length(); ++i)
            if (path[i] == '/') {
                if (i - k)
                    res.push_back(path.substr(k, i - k));
                k = i + 1;
            }

        return res;
    }

    FileSystem() {

    }

    vector<string> ls(string path) {
        folder* temp = fd;
        vector<string> folders = parsePath(path);

        for (const string& dir: folders) {
            if (!temp->subFolders.count(dir))
                temp->subFolders[dir] = new folder();
            temp = temp->subFolders[dir];
        }

        vector<string> ans;

        if (!temp->contents.empty())
            return {folders.back()};

        for (const auto& [k, v]: temp->subFolders)
            ans.push_back(k);

        sort(ans.begin(), ans.end());
        return ans;
    }

    void mkdir(string path) {
        folder* temp = fd;
        vector<string> folders = parsePath(path);

        for (const string& dir: folders) {
            if (!temp->subFolders.count(dir))
                temp->subFolders[dir] = new folder();
            temp = temp->subFolders[dir];
        }
    }

    void addContentToFile(string filePath, string content) {
        folder* temp = fd;
        vector<string> folders = parsePath(filePath);

        for (const string& dir: folders) {
            if (!temp->subFolders.count(dir))
                temp->subFolders[dir] = new folder();
            temp = temp->subFolders[dir];
        }

        temp->contents += content;
    }

    string readContentFromFile(string filePath) {
        folder* temp = fd;
        vector<string> folders = parsePath(filePath);

        for (const string& dir: folders) {
            if (!temp->subFolders.count(dir))
                temp->subFolders[dir] = new folder();
            temp = temp->subFolders[dir];
        }

        return temp->contents;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
