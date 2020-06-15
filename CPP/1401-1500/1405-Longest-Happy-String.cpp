class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char, int>> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});
        string ans;
        int ca(0), cb(0), cc(0);
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (p.second == 'a') {
                if (++ca == 3) {
                    --ca;
                    if (pq.empty())
                        return ans;
                    auto p2 = pq.top();
                    pq.pop();
                    ans += p2.second;
                    p2.first--;
                    if (p2.first > 0)pq.push(p2);
                    pq.push(p);
                    if (p2.second == 'b') {
                        ca = cc = 0;
                        cb++;
                    } else {
                        ca = cb = 0;
                        cc++;
                    }
                    continue;
                }
                cb = cc = 0;
            } else if (p.second == 'b') {
                if (++cb == 3) {
                    --cb;
                    if (pq.empty())
                        return ans;
                    auto p2 = pq.top();
                    pq.pop();
                    ans += p2.second;
                    p2.first--;
                    if (p2.first > 0)pq.push(p2);
                    pq.push(p);
                    if (p2.second == 'a') {
                        cb = cc = 0;
                        ca++;
                    } else {
                        ca = cb = 0;
                        cc++;
                    }
                    continue;
                }
                ca = cc = 0;
            } else {
                if (++cc == 3) {
                    --cc;
                    if (pq.empty())
                        return ans;
                    auto p2 = pq.top();
                    pq.pop();
                    ans += p2.second;
                    p2.first--;
                    if (p2.first > 0)pq.push(p2);
                    pq.push(p);
                    if (p2.second == 'b') {
                        ca = cc = 0;
                        cb++;
                    } else {
                        cc = cb = 0;
                        ca++;
                    }
                    continue;
                }
                ca = cb = 0;
            }
            ans += p.second;
            p.first--;
            if (p.first > 0) pq.push(p);
        }
        return ans;
    }
};
