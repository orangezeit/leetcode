    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int k = 0;
        vector<string> strs;
        
        while (k < words.size()) {
            int start = k;
            int w = 0;
            bool flag = false;
            
            while (w + words[k].length() <= maxWidth) {
                w += words[k].length() + 1;
                k++;
                if (k == words.size()) {
                    flag = true;
                    break;
                }
            }
            
            int num = k - start - 1;
            int space = maxWidth - w + k - start;
            string str;
            
            if (flag || num == 0) {
                for (int i = start; i < k; ++i) {
                    str += words[i];
                    if (space) {
                        str += " ";
                        space--;
                    }
                }
                
                if (space) {
                    str += string(space, ' ');
                }
                
            } else {
                int r = space % num;
                
                for (int i = start; i < k; ++i) {
                    str += words[i];
                    
                    if (i != k - 1) {
                        str += string(space / num, ' ');
                    }
                    
                    if (r) {
                        str += " ";
                        r--;
                    }
                }
            }

            strs.push_back(str);
        }
        
        return strs;
    }
