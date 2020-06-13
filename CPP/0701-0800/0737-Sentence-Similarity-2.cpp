class UnionFindDynamic {
private:
    unordered_map<string, int> ranks;
public:
    unordered_map<string, string> parents;

    string find(string i) {
        if (i != parents[i])
            parents[i] = find(parents[i]);
        return parents[i];
    }

    void unite(string i, string j) {
        string pi = find(i);
        string pj = find(j);
        ranks[pi] >= ranks[pj] ? parents[pj] = pi : parents[pi] = pj;
        if (ranks[pi] == ranks[pj]) ranks[pi]++;
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;

        UnionFindDynamic uf;
        for (const vector<string>& p: pairs) {
            if (!uf.parents.count(p[0]))
                uf.parents[p[0]] = p[0];
            if (!uf.parents.count(p[1]))
                uf.parents[p[1]] = p[1];
            uf.unite(p[0], p[1]);
        }

        for (const auto& p: uf.parents) {
            uf.parents[p.first] = uf.find(p.first);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            if (uf.parents[words1[i]] != uf.parents[words2[i]]) return false;
        }
        return true;
    }
};
