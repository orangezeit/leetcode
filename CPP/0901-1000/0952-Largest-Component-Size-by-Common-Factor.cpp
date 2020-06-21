class UnionFindStatic {
private:
    unordered_map<int, int> ranks;
public:
    unordered_map<int, int> parents;

    UnionFindStatic(const vector<int>& v) {
        for (const int& i: v) parents[i] = i;
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
    vector<int> find_primes(int n) {
        vector<int> nums(n + 1, 1);
        vector<int> primes;
        for (int i = 2; i <= n; ++i) {
            if (!nums[i]) continue;
            primes.push_back(i);
            for (int k = 2; k * i <= n; ++k) {
                nums[i * k] = 0;
            }
        }
        return primes;
    }

    int largestComponentSize(vector<int>& A) {
        int n(0);
        for (const int& a: A) n = max(n, a);
        vector<int> primes = find_primes(n);
        unordered_map<int, vector<int>> factors;
        UnionFindStatic uf = UnionFindStatic(A);
        //cout << "a";
        for (const int& a: A) {
            int t(a);
            for (int i = 0; i < primes.size(); ++i) {
                if (primes[i] > t) break;
                if (primes[i] > sqrt(a) && a == t) {
                    //cout << primes[i] << " " << a << endl;
                    factors[a].push_back(a);
                    break;
                }
                if (t % primes[i] == 0) {
                    factors[primes[i]].push_back(a);
                    while (t % primes[i] == 0) t /= primes[i];
                }
            }
        }
        for (auto& f: factors) {
            for (int i = 0; i + 1 < f.second.size(); ++i) {
                //cout << f[i] << " " << f[i+1] << endl;
                uf.unite(f.second[i], f.second[i+1]);
            }
        }

        unordered_map<int, int> g;
        int ans(0);

        for (const int& a: A) {
            ans = max(ans, ++g[uf.find(a)]);
        }

        return ans;
    }
};
