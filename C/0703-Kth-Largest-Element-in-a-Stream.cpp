private:
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
public:
    KthLargest(int k, vector<int> nums) {
        q = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        n = k;
        
        while (k < q.size()) {
            q.pop();
        }
    }
    
    int add(int val) {
        if (q.size() < n) {
            q.push(val);
        } else if (val > q.top()) {
            q.pop();
            q.push(val);
        }
        
        return q.top();
    }
