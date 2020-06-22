class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> s;
        int area(0);
        int x1(INT_MAX), y1(INT_MAX), x2(INT_MIN), y2(INT_MIN);

        for (const vector<int>& rect: rectangles) {

            x1 = min(x1, rect[0]);
            y1 = min(y1, rect[1]);
            x2 = max(x2, rect[2]);
            y2 = max(y2, rect[3]);

            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);

            string str1(to_string(rect[0]) + " " + to_string(rect[1]));
            string str3(to_string(rect[0]) + " " + to_string(rect[3]));
            string str2(to_string(rect[2]) + " " + to_string(rect[3]));
            string str4(to_string(rect[2]) + " " + to_string(rect[1]));

            if (s.count(str1)) {
                s.erase(str1);
            } else {
                s.insert(str1);
            }
            if (s.count(str2)) {
                s.erase(str2);
            } else {
                s.insert(str2);
            }
            if (s.count(str3)) {
                s.erase(str3);
            } else {
                s.insert(str3);
            }
            if (s.count(str4)) {
                s.erase(str4);
            } else {
                s.insert(str4);
            }
        }

        string str1(to_string(x1) + " " + to_string(y1));
        string str3(to_string(x1) + " " + to_string(y2));
        string str2(to_string(x2) + " " + to_string(y1));
        string str4(to_string(x2) + " " + to_string(y2));
        return s.size() == 4 && s.count(str1) && s.count(str2) && s.count(str3) && s.count(str4) && area == (y2 - y1) * (x2 - x1);
    }
};
