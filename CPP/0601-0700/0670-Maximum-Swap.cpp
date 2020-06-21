class Solution {
public:
    int maximumSwap(int num) {
        if (num < 10) {
            return num;
        }

        string str = to_string(num);
        int k = -1;

        for (int i = 0; i < str.length() - 1; ++i) {
            for (int j = i + 1; j < str.length(); ++j) {
                if (str[i] < str[j]) {
                    if (k == -1) {
                        //temp = str[j];
                        k = j;
                    } else if (str[k] <= str[j]) {
                        k = j;
                    }

                    //return stoi(str);
                }
            }
            //cout << str[i] << " " << temp << endl;
            if (k != -1) {
                swap(str[k], str[i]);
                return stoi(str);
            }
        }

        return stoi(str);
    }
};
