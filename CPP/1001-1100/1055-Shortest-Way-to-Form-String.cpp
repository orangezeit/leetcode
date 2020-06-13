class Solution {
public:
    int shortestWay(string source, string target) {
        vector<bool> letters(26, true);

        for (int i = 0; i < source.length(); ++i)
            letters[source[i] - 'a'] = false;

        int times(0);
        int k(0);
        int j(0);

        if (letters[target[j] - 'a'])
                return -1;

        while (j < target.length()) {

            while (k < source.length()) {

                if (source[k++] == target[j]) {

                    j++;
                    if (j == target.length())
                        break;
                    if (letters[target[j] - 'a'])
                        return -1;
                }

            }

            k = 0;
            times++;
        }

        return times;
    }
};
