class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        deque<int> dq(arr.begin(), arr.end());
        int e(*max_element(arr.begin(), arr.end()));
        unordered_map<int, int> mp;

        while (true) {
            int x = dq.front();
            dq.pop_front();
            if (x > dq.front()) {
                if (++mp[x] >= k) return x;
                dq.push_back(dq.front());
                dq.pop_front();
                dq.push_front(x);
            } else {
                if (++mp[dq.front()] >= k) return dq.front();
                dq.push_back(x);
            }
            if (dq.front() == e) break;
        }
        return e;
    }
};
