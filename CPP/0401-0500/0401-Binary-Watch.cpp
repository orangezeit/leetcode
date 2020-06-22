class Solution {
private:
    vector<int> pts = {1,2,4,8,1,2,4,8,16,32};
    unordered_set<string> hashset;
public:
    void watchHelper(int num, int hours, int minutes) {
        if (num == 0) {
            string str;

            if (hours < 12 && minutes < 60) {
                if (minutes < 10) {
                    str = to_string(hours) + ":0" + to_string(minutes);
                } else {
                    str = to_string(hours) + ":" + to_string(minutes);
                }

                hashset.insert(str);
            }
        } else {
            int k;

            for (int i = 0; i < pts.size(); ++i) {
                if (i > 3) {
                    if (minutes + pts[i] < 60 && pts[i] != 0) {
                        k = pts[i];
                        pts[i] = 0;
                        watchHelper(num-1, hours, minutes + k);
                        pts[i] = k;
                    }

                } else {
                    if (hours + pts[i] < 12 && pts[i] != 0) {
                        k = pts[i];
                        pts[i] = 0;
                        watchHelper(num-1, hours + k, minutes);
                        pts[i] = k;
                    }
                }
            }
        }
    }

    vector<string> readBinaryWatch(int num) {
        watchHelper(num, 0, 0);
        return vector<string>(hashset.begin(), hashset.end());

    }
};
