    bool lemonadeChange(vector<int>& bills) {
        int fives(0), tens(0);
        
        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5) {
                fives++;
            } else if (bills[i] == 10) {
                fives--;
                tens++;
            } else {
                if (tens) {
                    fives--;
                    tens--;
                } else {
                    fives -= 3;
                }
            }
            
            if (fives < 0 || tens < 0) {
                return false;
            }
        }
        
        return true;
    }
