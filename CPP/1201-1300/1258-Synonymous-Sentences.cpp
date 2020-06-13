class UnionFind {
public:
    unordered_map<string, string> m;

    string find(string s) {
        if (s != m[s])
            m[s] = find(m[s]);
        return m[s];
    }

    void unite(string s, string t) {
        string ps = find(s);
        string pt = find(t);
        m[ps] = pt;
    }
};

class Solution {
public:
    vector<string> ans;

    void build(unordered_map<int, set<string>>& w, vector<string>& parts, int i) {

        while (!w.count(i) && i < parts.size()) i++;

        if (i == parts.size()) {
            string s;
            for (string str: parts)
                s += str + ' ';
            s.pop_back();
            ans.push_back(s);
            return;
        }
        string temp = parts[i];
        for (const string& p: w[i]) {
            parts[i] = p;
            build(w, parts, i+1);
        }
        parts[i] = temp;
    }

    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        text += ' ';
        int k = 0;
        vector<string> parts;

        for (int i = 0; i < text.length(); ++i)
            if (text[i] == ' ') {
                parts.push_back(text.substr(k, i - k));
                k = i + 1;
            }

        UnionFind uf;

        for (const vector<string>& syn: synonyms) {
            if (!uf.m.count(syn[0]))
                uf.m[syn[0]] = syn[0];
            if (!uf.m.count(syn[1]))
                uf.m[syn[1]] = syn[1];
            uf.unite(syn[0], syn[1]);
        }

        unordered_map<string, set<string>> dicts;

        for (auto& p : uf.m)
            dicts[uf.find(p.first)].insert(p.first);

        unordered_map<int, set<string>> w;

        int i(0);
        for (const string& str: parts) {
            if (uf.m.count(str))
                w[i] = dicts[uf.m[str]];
            i++;
        }
        i = 0;
        build(w, parts, i);
        return ans;
    }
};
