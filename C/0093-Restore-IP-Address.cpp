    bool verifyNum(string str) {
        return (str[0] == '0' && str != "0") || stoi(str) > 255;
    }
    
    string makeAddress(int a, int b, int c, int d, string s) {
        if (verifyNum(s.substr(0, a)) || verifyNum(s.substr(a, b)) || verifyNum(s.substr(a+b, c)) || s.substr(a+b+c, d)) {
            return "na";
        }
        
        return s.substr(0, a) + "." + s.substr(a, b) + "." + s.substr(a+b, c) + "." + s.substr(a+b+c, d);
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<vector<int>> lengths;
        vector<string> address;
        string str;
        
        // Brute Force
        if(s.length() < 4) {
            return address;
        } else if (s.length() == 4) {
            lengths = {{1,1,1,1}};
        } else if (s.length() == 5) {
            lengths = {{2,1,1,1}, {1,2,1,1}, {1,1,2,1}, {1,1,1,2}};
        } else if (s.length() == 6) {
            lengths = {{3,1,1,1}, {1,3,1,1}, {1,1,3,1}, {1,1,1,3}, {2,2,1,1}, {2,1,2,1}, {2,1,1,2}, {1,2,2,1}, {1,2,1,2}, {1,1,2,2}};
        } else if (s.length() == 7) {
            lengths = {{2,2,2,1}, {2,2,1,2}, {2,1,2,2}, {1,2,2,2}, {1,1,2,3}, {1,2,1,3}, {1,2,3,1}, {2,1,1,3}, {2,1,3,1}, {2,3,1,1}, {1,1,3,2}, {1,3,1,2}, {1,3,2,1}, {3,1,1,2}, {3,1,2,1}, {3,2,1,1}};
        } else if (s.length() == 8) {
            lengths = {{2,2,2,2}, {1,3,2,2}, {1,2,3,2}, {1,2,2,3}, {2,1,3,2}, {2,1,2,3}, {2,2,1,3}, {3,1,2,2}, {3,2,1,2}, {3,2,2,1}, {2,3,1,2}, {2,3,2,1}, {2,2,3,1}, {1,1,3,3}, {1,3,1,3}, {1,3,3,1}, {3,1,1,3}, {3,1,3,1}, {3,3,1,1}};
        } else if (s.length() == 9) {
            lengths = {{2,2,2,3}, {2,2,3,2}, {2,3,2,2}, {3,2,2,2}, {3,3,1,2}, {3,1,3,2}, {3,1,2,3}, {1,3,3,2}, {1,3,2,3}, {1,2,3,3}, {3,3,2,1}, {3,2,3,1}, {3,2,1,3}, {2,3,3,1}, {2,3,1,3}, {2,1,3,3}};
        } else if (s.length() == 10) {
            lengths = {{1,3,3,3}, {3,1,3,3}, {3,3,1,3}, {3,3,3,1}, {2,2,3,3}, {2,3,2,3}, {2,3,3,2}, {3,2,2,3}, {3,2,3,2}, {3,3,2,2}};
        } else if (s.length() == 11) {
            lengths = {{2,3,3,3}, {3,2,3,3}, {3,3,2,3}, {3,3,3,2}};
        } else if (s.length() == 12) {
            lengths = {{3,3,3,3}};
        } else {
            return address;
        }
        
        for (int i = 0; i < lengths.size(); ++i) {
            str = makeAddress(lengths[i][0], lengths[i][1], lengths[i][2], lengths[i][3], s);
            if (str != "na") {
                address.push_back(str);
            }
        }
        
        return address;
    }
