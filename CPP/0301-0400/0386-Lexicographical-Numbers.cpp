    void addNum(vector<int>& nums, int num, int& k, int ten) {
        if (num % (10 * ten) == 0) {
            addNum(nums, num, k, 10 * ten);
        }
        
        nums[k++] = num / ten;
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> nums(n);
        
        int k = 0;
        int num = 1;
        
        while (num <= n) {
            nums[k++] = num;
            if (num == n) {
                break;
            }
            num *= 10;
        }
        
        num = num / 10 + 1;
        
        while (k < n) {
            if (num % 10 == 0) {
                addNum(nums, num, k, 10);
            }
            
            nums[k++] = num++;
            
            if (num > n) {
                num--;
                num = num / 10 + 1;
            }
        }
        
        return nums;
    }
