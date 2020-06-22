class Solution {
public:
    void diagonal(vector<int>& diag, vector<int> v1, vector<int> v2) {
        diag[0] = v1[0] - v2[0];
        diag[1] = v1[1] - v2[1];
    }

    bool test(vector<int> da, vector<int> db) {
        return da[0] * da[0] + da[1] * da[1] == db[0] * db[0] + db[1] * db[1] && da[0] * db[0] + da[1] * db[1] == 0;
    }

    bool midpoint(vector<int> v1, vector<int> v2, vector<int> v3, vector<int> v4) {
        return v1[0] + v2[0] == v3[0] + v4[0] && v1[1] + v2[1] == v3[1] + v4[1];
    }

    bool valid(vector<int> p1, vector<int> p2, vector<int> p3, vector<int> p4) {
        return p1 != p2 && p1 != p3 && p1 != p4 && p2 != p3 && p2 != p4 && p3 != p4;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (!valid(p1, p2, p3, p4)) {
            return false;
        }

        vector<int> d1(2), d2(2), d3(2), d4(2), d5(2), d6(2);
        diagonal(d1, p1, p2);
        diagonal(d2, p3, p4);

        if (test(d1, d2) && midpoint(p1, p2, p3, p4)) {
            return true;
        }

        diagonal(d3, p1, p3);
        diagonal(d4, p2, p4);

        if (test(d3, d4)&& midpoint(p1, p3, p2, p4)) {
            return true;
        }

        diagonal(d5, p1, p4);
        diagonal(d6, p2, p3);

        return test(d5, d6) && midpoint(p1, p4, p2, p3);

    }
};
