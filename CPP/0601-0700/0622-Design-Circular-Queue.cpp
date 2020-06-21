class MyCircularQueue {
private:
    vector<int> q;
    int n;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q.resize(k);
        n = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (n < q.size()) {
            q[n++] = value;
            return true;
        } else {
            return false;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
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

    /** Get the front item from the queue. */
    int Front() {
        if (n == 0) {
            return -1;
        } else {
            return q[0];
        }
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (n == 0) {
            return -1;
        } else {
            return q[n-1];
        }
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return n == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return n == q.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
