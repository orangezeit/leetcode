class Solution {
public:
    string findContestMatch(int n) {
        deque<string> dq;
        int i(1), j(n);
        while (i < j)
            dq.push_back("(" + to_string(i++) + "," + to_string(j--) + ")");
        while (dq.size() - 1) {
            deque<string> temp;
            while (!dq.empty()) {
                temp.push_back("(" + dq.front() + "," + dq.back() + ")");
                dq.pop_front();
                dq.pop_back();
            }
            dq = temp;
        }
        return dq.back();
    }
};
