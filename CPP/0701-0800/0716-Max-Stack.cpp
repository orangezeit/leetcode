class MaxStack {
private:
    vector<int> s;
public:
    /** initialize your data structure here. */
    MaxStack() {

    }

    void push(int x) {
        s.push_back(x);
    }

    int pop() {
        int x = s.back();
        s.pop_back();
        return x;
    }

    int top() {
        return s.back();
    }

    int peekMax() {
        int m = INT_MIN;
        for (int i = 0; i < s.size(); ++i) {
            m = max(m, s[i]);
        }
        return m;
    }

    int popMax() {
        int m = INT_MIN;
        for (int i = 0; i < s.size(); ++i) {
            m = max(m, s[i]);
        }

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == m) {
                s.erase(s.begin()+i);
                break;
            }
        }
        return m;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
