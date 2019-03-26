    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int idx(-1), spot(0);
        
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i]) {
                spot += (i-idx-1)/2;

                if (spot >= n) {
                    return true;
                }
                
                idx = i+1;
            }
        }

        return spot + (flowerbed.size()-idx)/2 >= n;
    }
