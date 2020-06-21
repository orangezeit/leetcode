class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (!n) return tasks.size();
        n++;
        unordered_map<char, int> record;
        priority_queue<pair<int, char>> pq;
        bool lastRow = true;

        for (const char& c: tasks) {
            record[c]++;
            lastRow &= (record[c] <= 1);
        }

        for (const auto& r: record)
            pq.push({r.second, r.first});

        int ans(0);

        while (!lastRow) {
            ans += n;
            vector<pair<int, char>> temp(n);
            int s = min(n, (int)pq.size());
            lastRow = true;

            for (int i = 0; i < s; ++i){
                temp[i] = pq.top();
                pq.pop();
                temp[i].first--;
                lastRow &= (temp[i].first <= 1);
            }

            for (int i = 0; i < s; ++i)
                if (temp[i].first)
                    pq.push(temp[i]);
            if (lastRow && pq.size() > n) lastRow = false;
        }

        return ans + pq.size();
    }
};
