    int maxDistToClosest(vector<int>& seats) {
        int n(seats.size()), k(-1), maxDist(1);
        
        for (int i = 0; i < n; ++i) {
            if (seats[i]) {
                if (k == -1) {
                    maxDist = max(maxDist, i);
                } else {
                    maxDist = max(maxDist, (i-k)/2);
                }
                k = i;
            }
        }
        
        return max(maxDist, n-k-1);
    }
