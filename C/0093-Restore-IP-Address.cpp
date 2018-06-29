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
        
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                for (int k = 1; k <= 3; ++k) {
                    for (int l = 1; l <= 3; ++l) {
                        if (i + j + k + l == s.length()) {
                            string str = makeAddress(i, j, k, l, s);
                            if (str != "na") {
                                address.push_back(str);
                            }
                        }
                    }
                }
            }
        }
        
        return address;
    }
