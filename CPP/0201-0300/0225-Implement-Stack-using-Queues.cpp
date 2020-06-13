private:
    queue<int> myStack;
    int s = 0;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        myStack.push(x);
        s++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp, c(s);
        
        while (c > 1) {
            temp = myStack.front();
            myStack.pop();
            myStack.push(temp);
            c--;
        }
        
        temp = myStack.front();
        myStack.pop();
        s--;
        
        return temp;
        
    }
    
    /** Get the top element. */
    int top() {
        int temp, c(s);
        
        while (c > 0) {
            temp = myStack.front();
            myStack.pop();
            myStack.push(temp);
            c--;
        }
        
        return temp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return s == 0;
    }
};
