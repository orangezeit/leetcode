class UnionFindStatic {
private:
    vector<int> ranks;
public:
    vector<int> parents;
    UnionFindStatic(int n) {
        parents.resize(n);
        ranks.resize(n);
        iota(parents.begin(), parents.end(), 0);
    }

    int find(int i) {
        if (i != parents[i])
            parents[i] = find(parents[i]);
        return parents[i];
    }

    void unite(int i, int j) {
        int pi = find(i);
        int pj = find(j);

        ranks[pi] >= ranks[pj] ? parents[pj] = pi : parents[pi] = pj;
        if (ranks[pi] == ranks[pj]) ranks[pi]++;
    }
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](const vector<int>& a, const vector<int>& b) {return a[2] < b[2];});
        //cout << "a";
        UnionFindStatic uf = UnionFindStatic(N);
        int costs(0);

        for (vector<int>& c: connections) {
            //cout << c.size() << endl;
            if (uf.find(c[0] - 1) != uf.find(c[1] - 1)) {
                //cout << "b";
                costs += c[2];
                uf.unite(c[0] - 1, c[1] - 1);
            }
        }
        //cout << "a";
        unordered_set<int> rec;
        for (const int& i: uf.parents) {
            rec.insert(uf.find(i));
            if (rec.size() > 1) return -1;
        }
        return costs;
    }
};
