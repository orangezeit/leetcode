class FreqStack {
public:
    unordered_map<int, int> freqs;
    vector<stack<int>> order;
    
    FreqStack() {
        
    }
    
    void push(int x) {
        int num = freqs[x];
        
        if (order.size() <= num) {
            stack<int> temp;
            temp.push(x);
            order.push_back(temp);
        } else {
            order[num].push(x);
        }
        
        freqs[x]++;
    }
    
    int pop() {
        int target = order.back().top();
        order.back().pop();
        if (order.back().empty())
            order.pop_back();
        freqs[target]--;
        return target;
    }
};
