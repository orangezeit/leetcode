class Solution {
public:

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int maxRad = 0;


            for (int k = 0; k < houses.size(); ++k) {
                int rad = 0;

                if (houses[k] <= heaters[0]) {
                    rad = heaters[0] - houses[k];
                } else if (houses[k] >= heaters.back()) {
                    rad = houses[k] - heaters.back();
                } else {
                    int i = 0;
                    int j = heaters.size() - 1;

                    while (j - i > 1) {
                        int m = j + (i-j)/2;

                        if (heaters[m] >= houses[k]) {
                            j = m;
                        } else {
                            i = m;
                        }
                    }

                    rad = min(houses[k] - heaters[i], heaters[j] - houses[k]);
                }

                maxRad = max(maxRad, rad);
            }


        return maxRad;
    }
};
