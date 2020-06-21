# define vars unordered_map<pair<int, string>, int, hash_pair>

struct hash_pair {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution {
public:
    const vars evaluate(queue<vars>& es, queue<char>& os) {

        deque<vars> qe;
        deque<char> qo;

        //if (es.size() == os.size()) {
            //qe.push_back({{{0, ""}, 0}});
        //} else {
            qe.push_back(es.front());
            es.pop();
        //}

        const auto sorted = [](const pair<int, string>& k1, const pair<int, string>& k2) {
            map<string, int> cnts;
            string t;

            for (const char& c: k1.second)
                if (c == '*') {
                    cnts[t]++;
                    t.clear();
                } else {
                    t += c;
                }
            cnts[t]++;
            t.clear();

            for (const char& c: k2.second)
                if (c == '*') {
                    cnts[t]++;
                    t.clear();
                } else {
                    t += c;
                }
            cnts[t]++;
            t.clear();

            for (const auto&[k, v]: cnts)
                for (int i = 0; i < v; ++i)
                    if (!k.empty())
                        t += k + '*';

            if (!t.empty()) t.pop_back();

            return make_pair(k1.first + k2.first, t);
        };

        while (!es.empty()) {
            if (os.front() == '*') {
                vars p;
                for (const auto& [k1, v1]: qe.back())
                    for (const auto& [k2, v2]: es.front())
                        p[sorted(k1, k2)] += v1 * v2;

                qe.pop_back();
                qe.push_back(p);
            } else {
                qo.push_back(os.front());
                qe.push_back(es.front());
            }
            es.pop();
            os.pop();
        }

        while (!qo.empty()) {
            auto e = qe.front();
            qe.pop_front();
            for (const auto& [k, v]: qe.front())
                qo.front() == '+' ? e[k] += v : e[k] -= v;
            qe.pop_front();
            qo.pop_front();
            qe.push_front(e);
        }

        return qe.front();
    }

    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        expression += '!';
        unordered_map<string, int> known;
        int n(evalvars.size());
        for (int i = 0; i < n; ++i)
            known[evalvars[i]] = evalints[i];

        stack<queue<vars>> operands;
        stack<queue<char>> operators;
        string t;
        vars res;
        operands.push({});
        operators.push({});

        const auto is_num = [](const string& s) {
            for (const char& c: s)
                if (!isdigit(c))
                    return false;
            return true;
        };

        for (const char& c: expression) {
            if (c == ' ') continue;
            if (c == '(') {
                operands.push({});
                operators.push({});
            } else if (isalnum(c)) {
                t += c;
            } else {

                if (!t.empty()) {
                    if (is_num(t)) {
                        operands.top().push({{{0, ""}, stoi(t)}});
                    } else if (known.count(t)) {
                        operands.top().push({{{0, ""}, known[t]}});
                    } else {
                        operands.top().push({{{-1, t}, 1}});
                    }
                }


                t.clear();

                if (c == ')') {
                    res = evaluate(operands.top(), operators.top());
                    operands.pop();
                    operators.pop();
                    operands.top().push(res);
                } else if (c == '!') {
                    res = evaluate(operands.top(), operators.top());
                    vector<pair<int, string>> keys(res.size());
                    int n = 0;
                    for (const auto&[k, v]: res)
                        if (v) keys[n++] = k;
                    keys.resize(n);
                    sort(keys.begin(), keys.end());
                    vector<string> ans(n);
                    for (int i = 0; i < n; ++i) {
                        ans[i] = to_string(res[keys[i]]);
                        if (!keys[i].second.empty()) ans[i] += "*" + keys[i].second;
                    }
                    return ans;
                } else {
                    operators.top().push(c);
                }
            }
        }

        return {};
    }
};
