    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start(0),total(0),tank(0);
        
        for (int i = 0; i < gas.size(); ++i) {
            tank = tank + gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                total += tank;
                tank = 0;
            }
        }
        
        if (total + tank < 0) {
            return -1;
        } else {
            return start;
        }
    }
