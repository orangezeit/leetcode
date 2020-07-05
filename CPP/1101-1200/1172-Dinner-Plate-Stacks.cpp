
class DinnerPlates {
public:
    deque<stack<int>> dq;
    int c, leftmost;

    DinnerPlates(int capacity) {
        c = capacity;
        leftmost = 0;
    }

    void push(int val) {

        if (dq.size() == leftmost)
            dq.push_back(stack<int>());

        dq[leftmost].push(val);

        while (dq[leftmost].size() == c) {
            if (++leftmost == dq.size()) {
                return;
            }
        }
    }

    int pop() {

        while (!dq.empty() && dq.back().empty()) dq.pop_back();
        if (dq.empty()) return -1;

        int val = dq.back().top();
        dq.back().pop();
        if (dq.back().empty()) {
            dq.pop_back();
            leftmost = min(leftmost, (int)dq.size());
        }
        return val;
    }

    int popAtStack(int index) {
        if (dq.size() <= index || dq[index].empty())
            return -1;
        int val = dq[index].top();
        dq[index].pop();
        leftmost = min(leftmost, index);
        return val;
    }
};



/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
