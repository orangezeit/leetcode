class H2O {
private:
    int h, o;
    mutex mu;
    condition_variable cv;
public:
    H2O() {
        h = 0;
        o = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        if (h == 2 && o == 1) {
            h = 0;
            o = 0;
        }
        unique_lock<mutex> lck(mu);
        while (h == 2) cv.wait(lck);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        h++;
        lck.unlock();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        if (h == 2 && o == 1) {
            h = 0;
            o = 0;
        }
        unique_lock<mutex> lck(mu);
        while (o == 1) cv.wait(lck);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        o++;
        lck.unlock();
        cv.notify_all();
    }
};
