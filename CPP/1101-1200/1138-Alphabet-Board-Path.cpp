class Solution {
public:
    string alphabetBoardPath(string target) {
        int curr_x(0), curr_y(0);
        string ans;

        for (int i = 0; i < target.length(); ++i) {
            int idx = target[i] - 'a';
            int new_x = idx % 5;
            int new_y = idx / 5;

            if (target[i] == 'z') {
                ans += new_x - curr_x > 0 ? string(new_x - curr_x, 'R') : string(curr_x - new_x, 'L');
                ans += new_y - curr_y > 0 ? string(new_y - curr_y, 'D') : string(curr_y - new_y, 'U');
            } else {
                ans += new_y - curr_y > 0 ? string(new_y - curr_y, 'D') : string(curr_y - new_y, 'U');
                ans += new_x - curr_x > 0 ? string(new_x - curr_x, 'R') : string(curr_x - new_x, 'L');
            }


            ans += '!';
            curr_x = new_x;
            curr_y = new_y;
        }

        return ans;
    }
};
