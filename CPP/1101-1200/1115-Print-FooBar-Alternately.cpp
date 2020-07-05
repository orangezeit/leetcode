class FooBar {
private:
    int n;
    int state;
    mutex mu;
    condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
        state = 0;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mu);
            while (state) cv.wait(lck);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            state = 1;
            lck.unlock();
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mu);
            while (!state) cv.wait(lck);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            state = 0;
            lck.unlock();
            cv.notify_all();
        }
    }
};
