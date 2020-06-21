class Solution {
public:
    string reorganizeString(string S) {
        int record[26] = {};
        priority_queue<pair<int, char>> pq;

        for (const char& c: S)
            record[c - 'a']++;

        for (char c = 'a'; c <= 'z'; ++c)
            pq.push({record[c - 'a'], c});

        string ans;
        while (pq.size() > 1) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            ans += p1.second;
            ans += p2.second;
            if (--p1.first) pq.push(p1);
            if (--p2.first) pq.push(p2);
        }

        return pq.empty() ? ans : pq.top().first > 1 ? "" : ans + pq.top().second;
    }
};
