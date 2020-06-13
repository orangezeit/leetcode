class Solution {
public:


    void permuteHelper(string& str, string& permute, vector<string>& permutes) { // from #47 permutation 2
        if (permute.length() == str.length()) {
            permutes.push_back(permute);
        } else {
            for (int i = 0; i < str.length(); ++i) {
                if (str[i] == ' ') continue;
                if (i && str[i] == str[i - 1]) continue;

                permute += str[i];
                str[i] = ' ';
                permuteHelper(str, permute, permutes);
                str[i] = permute.back();
                permute.pop_back();

            }
        }
    }

    vector<string> generatePalindromes(string s) {
        map<char, int> cnts;
        int odds(0);
        char mid(' ');
        string str, permute;
        vector<string> permutes;
        for (const char& c: s) cnts[c]++;

        for (auto& p: cnts) {
            if (p.second % 2) {
                if (odds++) return {};
                mid = p.first;
            }
            str += string(p.second / 2, p.first);

        }
        permuteHelper(str, permute, permutes);

        for (string& pm: permutes) {
            string temp = pm;
            reverse(temp.begin(), temp.end());
            pm += mid != ' ' ? mid + temp : temp;
        }

        return permutes;
    }
};
