class Solution {
public:
    //a->c
    //b->d
    //c->e // topological sort

    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        unordered_map<char, char> rec;

        for (int i = 0; i < str1.length(); ++i) {
            if (rec.count(str1[i]) && rec[str1[i]] != str2[i]) return false;
            rec[str1[i]] = str2[i];
        }
        unordered_set<char> s;
        for (auto& p: rec) s.insert(p.second);
        return s.size() != 26;
    }
};
