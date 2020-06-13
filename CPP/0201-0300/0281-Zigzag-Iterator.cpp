class ZigzagIterator {
private:
    int i = 0;
    int j = 0;
    vector<int> n1, n2;
    bool flag = true;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        n1 = v1;
        n2 = v2;
    }

    int next() {
        int num;
        if (i >= n1.size())
            return n2[j++];
        if (j >= n2.size())
            return n1[i++];
        if (flag) {
            num = n1[i++];
        } else {
            num = n2[j++];
        }

        flag = !flag;
        return num;
    }

    bool hasNext() {
        return i < n1.size() || j < n2.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
