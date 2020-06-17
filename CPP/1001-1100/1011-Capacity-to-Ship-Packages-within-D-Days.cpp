class Solution {
public:
    int countDays(const vector<int>& weights, int capacity) {
        int a(0);
        int cargo(0);
        for (const int& w: weights) {
            if (cargo + w <= capacity) cargo += w;
            else {
                cargo = w;
                a++;
            }
        }

        return a + 1;
    }
    int shipWithinDays(const vector<int>& weights, const int& D) {
        int left = 0;
        int right = 1;
        for (const int& w: weights) {
            left = max(left, w);
            right += w;
        }
        left--;
        while (right - left > 1) {
            int m = (left + right) / 2;
            if (countDays(weights, m) > D) {
                left = m;
            } else {
                right = m;
            }
            //cout << countDays(weights, m) << endl;
            //break;
        }

        //cout << left << " " << right << endl;
        return right;
    }
};
