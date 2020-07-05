class Solution {
public:
    vector<int> closestDivisors(int num) {
        int a(num + 1), b(num + 2), c(0), d(1000000001);
        for (int i = int(sqrt(a)) + 1; i >= 1; --i) {
            if (a % i == 0) {
                if (abs(i - a / i) < abs(d - c)) {
                    c = a / i;
                    d = i;
                    break;
                }
            }
        }
        for (int i = int(sqrt(b)) + 1; i >= 1; --i) {
            if (b % i == 0) {
                //cout << i << endl;
                if (abs(i - b / i) < abs(d - c)) {

                    c = b / i;
                    d = i;
                    break;
                }
            }
        }
        return {c, d};
    }
};
