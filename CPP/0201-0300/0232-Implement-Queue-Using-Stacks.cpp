private:
    stack<int> myQueue, backup;
    int s = 0;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        myQueue.push(x);
        s++;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp, answer, c(s);
        
        while (c > 0) {
            temp = myQueue.top();
            myQueue.pop();
            backup.push(temp);
            c--;
        }
        
        answer = temp;
        backup.pop();
        s--;
        
        while (c < s) {
            myQueue.push(backup.top());
            backup.pop();
            c++;
        }
        
        return answer;
    }
    
    /** Get the front element. */
    int peek() {
        int temp, answer, c(s);
        
        while (c > 0) {
            temp = myQueue.top();
            myQueue.pop();
            backup.push(temp);
            c--;
        }
        
        answer = temp;
        
        while (c < s) {
            myQueue.push(backup.top());
            backup.pop();
            c++;
        }
        
        return answer;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s == 0;
    }
