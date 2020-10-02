
template<typename T, T M>
struct modint {
    T n;
    constexpr modint(const T n = 0) : n((n % M + M) % M) {}
    constexpr modint pow(T r) const {
        modint ans(1), a(n);
        while(r) { if (r & 1) ans *= a; a *= a; r >>= 1; }
        return ans;
    }
    constexpr modint& operator+= (const modint r) {
        n += r.n; if (n >= M) n -= M; return *this;
    }
    constexpr modint& operator-= (const modint r) {
        n -= r.n; if (n < 0) n += M; return *this;
    }
    constexpr modint& operator*= (const modint r) {
        n = n * r.n % M; return *this;
    }
    constexpr modint operator+ (const modint r) const { return modint(n) += r; }
    constexpr modint operator- (const modint r) const { return modint(n) -= r; }
    constexpr modint operator* (const modint r) const { return modint(n) *= r; }
    /* Divisions only work for prime modules */
    constexpr modint& operator/= (const modint r) { return (*this) *= r.pow(M-2); }
    constexpr modint operator/ (const modint r) const { return modint(n) /= r; }
};

template<typename T>
    struct modfact {
    vector<T> fact, invfact;
    constexpr modfact(int n): fact(n + 1), invfact(n + 1) {
        fact[0] = T(1);
        for(int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * T(i);
        invfact[n] = T(1) / fact[n];
        for(int i = n - 1; i >= 0; --i)
        invfact[i] = invfact[i + 1] * T(i + 1);
    }
    constexpr T p(int n, int k) const {
        // permutations: n! / k!
        if (k < 0 || k > n) return T(0);
        return fact[n] * invfact[k];
    }
    constexpr T c(int n, int k) const {
        // combinations(binomial coefficient): n! / (k! * (n - k)!)
        if (k < 0 || k > n) return T(0);
        return p(n, k) * invfact[n - k];
    }
};



class Solution {
public:
    typedef modint<long, 1000000007L> mint;
    int numOfWays(vector<int>& nums) {
        modfact<mint> mf(nums.size());
        function<mint(const vector<int>&)> f = [&](const vector<int>& v) {
            if (v.size() <= 1) return mint(1);
            vector<int> left, right;
            for (int i = 1; i < v.size(); i++)
                v[i] < v[0] ? left.emplace_back(v[i]) : right.emplace_back(v[i]);
            return f(left) * f(right) * mf.c(v.size() - 1, right.size());
        };
        return (f(nums) - mint(1)).n;
    }
};
