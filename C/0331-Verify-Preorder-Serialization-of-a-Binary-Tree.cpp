    bool isValidSerialization(string preorder) {
        if (preorder == "#") {
            return true;
        }
        preorder += ',';
        stack<string> s;
        
        int k = -1;
        for (int i = 0; i < preorder.length(); ++i) {
            if (preorder[i] == ',') {
                string str = preorder.substr(k+1, i-k-1);
                if (str != "#") {
                    s.push(str);
                } else if (s.empty()) {
                    return false;
                } else if (s.top() != "#") {
                    s.push(str);
                } else {
                    while (s.top() == "#") {
                        s.pop();
                        if (s.empty()) {
                            return false;
                        } else if (s.top() == "#") {
                            return false;
                        }
                        s.pop();
                        if (s.empty()) {
                            break;
                        }
                    }
                    
                    s.push(str);
                }
                k = i;
            }
        }
        if (s.top() == "#") {
            s.pop();
        }
        return s.empty();
    }
