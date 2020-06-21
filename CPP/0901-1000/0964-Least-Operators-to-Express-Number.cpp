class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        // steps, num
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> visited;

        pq.push({0, target});

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            //cout << p.first << " " << p.second << endl;
            // if (p.second <= x) return p.first + min(2 * (x - p.second) + 1, 2 * p.second) - 1;
            if (p.second == 0) return p.first - 1;
            if (visited.count(p.second)) continue;
            //cout << p.second << endl;
            visited.insert(p.second);


            int b = log(p.second) / log(x);
            int c1 = pow(x, b + 1) - p.second;
            int c2 = p.second - pow(x, b);

            if (!visited.count(c1))
                pq.push({p.first + b + 1, c1});

            if (!visited.count(c2))
                pq.push({p.first + (b ? b : 2), c2});

        }

        return -1;
    }
};
