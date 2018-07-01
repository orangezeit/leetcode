    int numSquares(int n) {
        // Method 1: Dynamic Programming
        vector<int> record(n+1, 1);
        
        for (int i = 0; i <= n; ++i) {
            record[i] = i;
            for (int j = 1; j * j <= i; j++) {
                record[i] = min(record[i], record[i-j*j] + 1);
            }
        }
        
        return record.back();
        
        // Method 2: Breadth-First Search
        queue<pair<int, int>> q;
        q.push({n, 0});
        vector<bool> visited(n, false);
        
        while (!q.empty()) {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            
            for (int i = 1; i * i <= num; ++i) {
                if (num == i * i) {
                    return step + 1;
                } else if (!visited[num-i*i]) {
                    q.push({num-i*i, step+1});
                    visited[num-i*i] = true;
                }
            }
        }
    }
