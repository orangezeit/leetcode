class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {

        int first(-1), last(256), c(0), c_max(0), c_acc(0), s_mode;
        double s_sum(0);
        double s_median;

        while (!count[++first]) {};
        while (!count[--last]) {};

        for (int i = first; i <= last; ++i) {
            if (count[i]) {
                s_sum += count[i] * i;
                c += count[i];
                if (count[i] > c_max) {
                    c_max = count[i];
                    s_mode = i;
                }
            }
        }

        for (int i = first; i <= last; ++i) {
            c_acc += count[i];
            if (c_acc >= (c + 1) / 2) {
                s_median = i;
                if (!(c % 2) && c_acc == (c + 1) / 2) {
                    while (!count[++i]) {};
                    s_median += i;
                    s_median /= 2;
                }
                break;
            }
        }

        return vector<double>({first, last, s_sum * 1.0 / c, s_median, s_mode});
    }
};
