class Solution {
public:
    string frequencySort(string s) {
        int chars[128] = {};

        priority_queue<pair<int, char>> pq;
        string ans;

        for (const char& c: s) chars[c]++;

        for (int i = 0; i < 128; ++i)
            if (chars[i])
                pq.push({chars[i], i});

        while (!pq.empty()) {
            ans += string(pq.top().first, pq.top().second);
            pq.pop();
        }

        return ans;


    }
};
