class RLEIterator {
private:
    queue<pair<int, int>> record;
public:
    RLEIterator(vector<int> A) {
        for (int i = 0; i < A.size(); i += 2) {
            if (A[i] == 0) continue;
            record.push({A[i], A[i+1]});
        }
    }

    int next(int n) {
        if (record.empty()) return -1;

        while (n > record.front().first) {
            n -= record.front().first;
            record.pop();
            if (record.empty()) return -1;
        }

        record.front().first -= n;
        return record.front().second;
    }
};
