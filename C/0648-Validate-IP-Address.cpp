    string validIPAddress(string IP) {
        if (IP.length() < 7) {
            return "Neither";
        }
        int k = -1;
        int dots = 0;
        
        for (int i = 0; i < 5; ++i) {
            if (IP[i] == '.') {
                IP += '.';
                for (int j = 0; j < IP.length(); ++j) {
                    if (IP[j] != '.') {
                        if (IP[j] < '0' || IP[j] > '9') {
                            return "Neither";
                        }
                    } else {
                        dots++;
                        if (dots > 4) {
                            return "Neither";
                        }
                        
                        if (j-k == 1) {
                            return "Neither";
                        }
                        
                        if (IP.substr(k+1, j-k-1)[0] == '0' && IP.substr(k+1, j-k-1) != "0") {
                            return "Neither";
                        }
                        
                        if (stoi(IP.substr(k+1, j-k-1)) > 255) {
                            return "Neither";
                        }
                        
                        k = j;
                    }
                }
                
                if (dots != 4) {
                    return "Neither";
                }
                
                return "IPv4";
            } else if (IP[i] == ':') {
                IP += ':';
                for (int j = 0; j < IP.length(); ++j) {
                    if (IP[j] != ':') {
                        if ((IP[j] < '0' || IP[j] > '9') && (IP[j] < 'a' || IP[j] > 'f') && (IP[j] < 'A' || IP[j] > 'F')) {
                            return "Neither";
                        }
                    } else {
                        dots++;
                        if (dots > 8) {
                            return "Neither";
                        }
                        if (j - k == 1 || j - k  > 5) {
                            return "Neither";
                        }
                        k = j;
                    }
                }
                
                if (dots != 8) {
                    return "Neither";
                }
                
                return "IPv6";
            }
        }
        
        return "Neither";
    }
