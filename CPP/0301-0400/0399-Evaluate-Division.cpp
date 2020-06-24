template<typename T>
struct DynamicUnion { // special case
    unordered_map<T, T> parents;

    constexpr T find(const T& x) {
        if (x != parents[x])
            parents[x] = find(parents[x]);
        return parents[x];
    }

    constexpr void unite(const T& x, const T& y) {
        const T px(find(x)), py(find(y));
        if (px != py) parents[px] = py;
    }
};


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& es, vector<double>& vs,
                                vector<vector<string>>& qs) {
        DynamicUnion<string> uf;
        unordered_map<string, double> vars;

        for (int i = 0; i < vs.size(); ++i) {
            if (uf.parents[es[i][0]].empty()) uf.parents[es[i][0]] = es[i][0];
            if (uf.parents[es[i][1]].empty()) uf.parents[es[i][1]] = es[i][1];

            if (!vars.count(es[i][0]) && !vars.count(es[i][1])) {
                vars[es[i][0]] = vs[i];
                vars[es[i][1]] = 1.0;
            } else if (!vars.count(es[i][0])) {
                vars[es[i][0]] = vars[es[i][1]] * vs[i];
            } else if (!vars.count(es[i][1])) {
                vars[es[i][1]] = vars[es[i][0]] / vs[i];
            } else {

                double x = vars[es[i][1]];

                for (const auto& [k, v]: uf.parents) {
                    if (v == es[i][0])
                        vars[k] *= x * vs[i];
                }
            }
            uf.unite(es[i][0], es[i][1]);
        }

        for (const auto& [k, v]: uf.parents)
            uf.find(k);

        vector<double> res(qs.size(), -1.0);

        for (int i = 0; i < qs.size(); ++i)
            if (uf.parents.count(qs[i][0]) && uf.parents.count(qs[i][1])
                                           && uf.parents[qs[i][0]] == uf.parents[qs[i][1]])
                res[i] = vars[qs[i][0]] / vars[qs[i][1]];

        return res;
    }
};
