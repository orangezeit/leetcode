    string simplifyPath(string path) {
        vector<string> pathStack;
        path += "/";
        
        int k = -1;
        
        for (int i = 0; i < path.length(); ++i) {
            if (path[i] == '/') {
                if (k + 1 != i) {
                    string temp = path.substr(k+1, i-k-1);
                    if (temp == "..") {
                        if (!pathStack.empty()) {
                            pathStack.pop_back();
                        }
                    } else if (temp != ".") {
                        pathStack.push_back(temp);
                    }
                }
                k = i;
            }
        }
        
        if (pathStack.empty()) {
            return "/";
        } else {
            string str;
            for (int i = 0; i < pathStack.size(); ++i) {
                str += ("/" + pathStack[i]);
            }
            return str;
        }
    }
