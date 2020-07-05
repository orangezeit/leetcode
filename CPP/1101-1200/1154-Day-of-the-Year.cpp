class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8));

        vector<int> series({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
        if (year % 400 == 0) {
            series[1]++;
        } else if (year % 4 == 0 && year % 100 != 0) {
            series[1]++;
        }
        int sum(0);
        for (int i = 0; i < month - 1; ++i) {
            sum += series[i];
        }
        return sum + day;
    }
};
