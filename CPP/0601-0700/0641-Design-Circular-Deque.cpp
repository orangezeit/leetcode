class MyCircularDeque {
private:
    vector<int> q;
    int n;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        q.resize(k);
        n = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (n < q.size()) {
            for (int i = n; i >= 1; --i) {
                q[i] = q[i-1];
            }
            q[0] = value;
            n++;
            return true;
        } else {
            return false;
        }
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (n < q.size()) {
            q[n++] = value;
            return true;
        } else {
            return false;
        }
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (n != 0) {
            for (int i = 0; i < n-1; ++i) {
                q[i] = q[i+1];
            }
            n--;
            return true;
        } else {
            return false;
        }
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (n != 0) {
            n--;
            return true;
        } else {
            return false;
        }
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (n == 0) {
            return -1;
        } else {
            return q[0];
        }
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (n == 0) {
            return -1;
        } else {
            return q[n-1];
        }
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return n == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return n == q.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */
