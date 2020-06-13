    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        int remain = n;
        bool left = true;
        
        while (remain > 1) {
            if (left || remain % 2) {
                head += step;
            }
            
            step *= 2;
            remain /= 2;
            left = !left;
            
        }
        
        return head;
    }
