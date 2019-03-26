    int totalHammingDistance(vector<int>& nums) {
        int n(nums.size()), distSum(0);
        vector<vector<int>> binums(n, vector<int>(32, 0));
        
        for (int i = 0; i < n; ++i) {
            int k = 0;
            
            while (nums[i]) {
                binums[i][k++] = nums[i] % 2;
                nums[i] /= 2;
            }
        }
        
        for (int i = 0; i < 32; ++i) {
            int c = 0;
            
            for (int j = 0; j < n; ++j) {
                if (binums[j][i]) {
                    c++;
                }
            }
            
            distSum += c * (n - c);
        }
        
        return distSum;
    }
