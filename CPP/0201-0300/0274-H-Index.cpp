    int hIndex(vector<int>& citations) {
        if (citations.empty()) {
            return 0;
        }
        
        sort(citations.rbegin(), citations.rend());
        
        for (int i = 0; i < citations.size(); ++i) {
            if (i >= citations[i]) {
                if (i+1 < citations.back()) {
                    return citations.back();
                } else if (i+1 > citations[0]) {
                    return citations[0];
                } else if (citations[i] > i) {
                    return citations[i];
                } else {
                    return i;
                }
            }
        }
        
        return citations.size();
    }
