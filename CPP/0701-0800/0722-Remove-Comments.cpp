    vector<string> removeComments(vector<string>& source) {
        vector<int> p(2);
        
        for (int i = 0; i < source.size(); ++i) {
            if (source[i].empty()) continue;
            
            for (int j = 0; j < source[i].length() - 1; ++j) {
                if (source[i][j] == '/' && source[i][j + 1] == '/' && p.empty()) {
                    source[i] = source[i].substr(0, j);
                    break;
                } else if (source[i][j] == '/' && source[i][j + 1] == '*' && p.empty()) {
                    p[0] = i;
                    p[1] = j;
                } else if (source[i][j] == '*' && source[i][j+1] == '/' && !p.empty()) {
                    if (i == p[0] && j == p[1] + 1) continue; // avoid /*/
                    source[p[0]] = source[p[0]].substr(0, p[1]) + source[i].substr(j + 2, source[i].length() - j - 2);
                    for (int k = p[0] + 1; k <= i; ++k) source[k].clear();
                    i = p[0] - 1;
                    p.clear();
                    break;
                }
            }
        }
        
        int m = 0;
        int n = 0;
        
        while (m < source.size()) {
            if (source[m].empty()) m++;
            else source[n++] = source[m++];
        }
        
        source.resize(n);
        return source;
    }
