    vector<int> verList(string version) {
        version += '.';
        vector<int> ver;
        int k = 0;
        
        for (int i = 0; i < version.length(); ++i) {
            if (version[i] == '.') {
                ver.push_back(stoi(version.substr(k, i-k)));
                k = i + 1;
            }
        }
        
        while (ver.back() == 0) {
            ver.pop_back();
        }
        
        return ver;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> ver1(verList(version1)), ver2(verList(version2));
        
        if (ver1 == ver2) {
            return 0;
        }
        
        for (int i = 0; i < min(ver1.size(), ver2.size()); ++i) {
            if (ver1[i] > ver2[i]) {
                return 1;
            } else if (ver1[i] < ver2[i]) {
                return -1;
            }
        }
        
        return ver1.size() > ver2.size() ? 1 : -1;
    }
