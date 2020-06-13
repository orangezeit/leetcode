    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i(1), j(numbers.size());
        
        while(numbers[i-1] + numbers[j-1] != target) {
            if (numbers[i-1] + numbers[j-1] > target) {
                j--;
            } else {
                i++;
            }
        }
        
        return vector<int>({i,j});
    }
