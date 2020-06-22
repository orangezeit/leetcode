class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> used;

        for (string& s: names) {
            if (used.count(s)) {
                int k = used[s];
                string file;
                while (used.count(file = s + "(" + to_string(k) + ")")) {
                    k++;
                    used[s]++;
                }
                s = file;
            }
            used[s]++;
        }
        return names;
    }
};
