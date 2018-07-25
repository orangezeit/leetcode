    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 0;
        int right = 0;
        
        for (int i = 0; i < piles.size(); ++i) {
            right = max(right, piles[i]);
        }
        
        while (right - left > 1) {
            int middle = (left + right) / 2;
            int h = 0;
            
            for (int i = 0; i < piles.size(); ++i) {
                h += piles[i] / middle;
                if (piles[i] % middle) {
                    h++;
                }
            }
            
            h > H ? left = middle : right = middle;
        }
        
        return right;
    }
