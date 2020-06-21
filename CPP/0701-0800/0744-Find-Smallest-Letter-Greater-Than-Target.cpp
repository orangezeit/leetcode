class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0;
        int j = letters.size()-1;

        if (target < letters[i] || target >= letters[j]) {
            return letters[i];
        }

        while (j - i > 1) {
            if (target < letters[(i+j)/2]) {
                j = (i+j)/2;
            } else {
                i = (i+j)/2;
            }
        }

        return letters[j];
    }
};
