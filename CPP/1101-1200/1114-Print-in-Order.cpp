class Foo {
private:
    int n;
    mutex mu;
    condition_variable cv;
public:
    Foo() {
        n = 0;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(mu);
        while (n != 0) cv.wait(lck);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        n++;
        lck.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mu);
        while (n != 1) cv.wait(lck);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        n++;
        lck.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mu);
        while (n != 2) cv.wait(lck);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        n++;
        lck.unlock();
        cv.notify_all();
    }
};
