class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& fc) {
        int n(fc.size()), k(0);
        unordered_map<string, int> labels;
        for (const vector<string>& f: fc)
            for (const string& c: f)
                if (!(labels.count(c)))
                    labels[c] = k++;

        bitset<100> marks;
        marks.set();
        vector<bitset<50000>> info(n);
        vector<int> ans;

        for (int i = 0; i < n; ++i)
            for (const string& c: fc[i])
                info[i][labels[c]] = 1;

        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j) {
                bitset<50000> check = info[i] & info[j];


                if (check == info[i]) marks[i] = 0;
                if (check == info[j]) marks[j] = 0;
            }
        }

        for (int i = 0; i < n; ++i)
            if (marks[i])
                ans.push_back(i);
        return ans;
    }
};
