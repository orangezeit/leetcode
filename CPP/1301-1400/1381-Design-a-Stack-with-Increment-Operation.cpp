class CustomStack {
public:
    deque<int> dq;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }

    void push(int x) {
        if (dq.size() == n) return;
        dq.push_back(x);
    }

    int pop() {
        if (dq.empty()) return -1;
        int x = dq.back();
        dq.pop_back();
        return x;
    }

    void increment(int k, int val) {
        auto end = k > dq.size() ? dq.end() : (dq.begin() + k);
        for (auto it = dq.begin(); it != end; ++it) {
            (*it) += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
