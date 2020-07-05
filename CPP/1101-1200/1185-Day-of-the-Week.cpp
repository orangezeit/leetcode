class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int init_year = 1971;
        int total(4);
        string weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        while (init_year < year) {
            int cnt(365);

            if (!(init_year % 4) && (init_year % 100)) cnt++;
            if (!(init_year % 400)) cnt++;

            total += cnt;
            init_year++;
        }

        if (!(year % 4) && (year % 100)) days[1]++;
        if (!(year % 400)) days[1]++;
        //cout << days[1] << endl;
        for (int i = 0; i < month - 1; ++i) {
            total += days[i];
        }

        total += day;

        return weekdays[total % 7];
    }
};
