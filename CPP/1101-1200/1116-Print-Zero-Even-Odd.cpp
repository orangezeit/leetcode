class ZeroEvenOdd {
private:
    int n;
    int c;
    mutex m0, m1, m2;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        c = 1;
        m1.lock();
        m2.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (c <= n) {
            m0.lock();
            if (c <= n) printNumber(0);
            c % 2 ? m1.unlock() : m2.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        while (c <= n) {
            m2.lock();
            if (c <= n) printNumber(c++);
            m0.unlock();
        }

    }

    void odd(function<void(int)> printNumber) {
        while (c <= n) {
            m1.lock();
            if (c <= n) printNumber(c++);
            m0.unlock();
        }
    }
};
