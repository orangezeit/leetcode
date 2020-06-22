struct fraction {
    int n, d;
    fraction(int nn, int dd) {
        if (nn == 0) {
            n = 0;
            d = 1;
            return;
        }

        if (dd < 0) {
            nn = -nn;
            dd = -dd;
        }
        int g = gcd(abs(nn), abs(dd));
        n = nn / g;
        d = dd / g;
    }
    fraction(int nn) : n(nn), d(1) {}
    fraction operator+ (fraction other) {
        return fraction(n * other.d + d * other.n, d * other.d);
    }
    fraction operator- (fraction other) {
        return fraction(n * other.d - d * other.n, d * other.d);
    }
    fraction operator* (fraction other) {
        return fraction(n * other.n, d * other.d);
    }
    fraction operator/ (fraction other) {
        assert(other.n != 0);
        return fraction(n * other.d, d * other.n);
    }
};

class Solution {
private:
    vector<vector<int>> permutes;
public:
    void permuteHelper(vector<int>& nums, vector<int>& permute) {
        if (permute.size() == nums.size()) {
            permutes.push_back(permute);
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == -1) continue;
                if (i && nums[i] == nums[i-1]) continue;
                permute.push_back(nums[i]);
                nums[i] = -1;
                permuteHelper(nums, permute);
                nums[i] = permute.back();
                permute.pop_back();
            }
        }
    }

    void permute(vector<int>& nums) {
        vector<int> permute;
        permuteHelper(nums, permute);
    }

    unordered_map<int, vector<fraction>> res;

    vector<fraction> bisect(const vector<int>& nums, int i, int j) {
        if (i + 1 == j) return vector<fraction>({fraction(nums[i])});
        if (res.count(i * nums.size() + j)) return res[i + nums.size() + j];

        vector<fraction> ans;

        for (int k = i + 1; k < j; ++k) {
            vector<fraction> ra = bisect(nums, i, k);
            vector<fraction> rb = bisect(nums, k, j);

            for (auto& d1: ra)
                for (auto& d2: rb) {
                    ans.push_back(d1 + d2);
                    ans.push_back(d1 - d2);
                    ans.push_back(d1 * d2);
                    if (d2.n != 0) ans.push_back(d1 / d2);
                }
        }

        res[i + nums.size() + j] = ans;
        return ans;
    }

    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        permute(nums);

        for (const vector<int>& v: permutes) {
            vector<fraction> total = bisect(v, 0, nums.size());
            for (const auto& f: total)
                if (f.n == 24 && f.d == 1)
                    return true;
            res.clear();
        }

        return false;
    }
};
