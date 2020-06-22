// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int i = rand7();
        int j = rand7();

        while (i > 5) {
            i = rand7();
        }

        while (j > 6) {
            j = rand7();
        }

        return j % 2 ? i : i + 5;
    }
};
