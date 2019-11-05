class Solution1201 {
public:
    int nthUglyNumber(int n, long a, long b, long c) {
        // find n-th ugly number which is divisible by a or b or c
        // given an integer m
        // the number of ugly numbers under m is
        // (Venn graph) k = m / a + m / b + m / c - m / lcm(ab) - m / lcm(ac) - m / lcm(bc) + m / lcm(abc)
        // binary search to find min m such that k = n
        long l = 1;
        long r = INT_MAX;
        long ab = lcm(a, b);
        long bc = lcm(b, c);
        long ac = lcm(a, c);
        long abc = lcm(a, bc);

        while (l < r) {
            long m = l + (r - l) / 2;
            long k = m / a + m / b + m / c - m / ab - m / bc - m / ac + m / abc;
            k >= n ? r = m : l = m + 1;
        }

        return l;
    }
};

class Solution1202 {
private:
    vector<int> ones;
    string t;
    int find(int x) {
        if (x != ones[x])
            ones[x] = find(ones[x]);
        return ones[x];

    }
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px != py) ones[px] = py;
    }

    void swapLetters(string& s, const vector<int>& indices) {
        vector<int> vec = indices;
        t = s;

        sort(vec.begin(), vec.end(), [&s](const size_t& t1, const size_t& t2){
            return s[t1] < s[t2];
        });

        for (int i = 0; i < indices.size(); ++i)
            t[indices[i]] = s[vec[i]];
        s = t;
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        ones.resize(s.length());
        iota(ones.begin(), ones.end(), 0);

        for (const vector<int>& pair: pairs)
            unite(pair[0], pair[1]);

        unordered_map<int, vector<int>> rec;

        for (int i = 0; i < s.length(); ++i)
            rec[find(i)].push_back(i);

        for (const auto& r: rec) {
            swapLetters(s, r.second);
        }

        return s;
    }
};

class Solution1207 {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnts;
        unordered_set<int> rec;

        for (const int& n: arr) cnts[n]++;
        for (const auto& p: cnts) {
            if (rec.count(p.second))
                return false;
            rec.insert(p.second);
        }
        return true;
    }
};

class Solution1208 {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> costs(s.length());
        for (int i = 0; i < s.length(); ++i)
            costs[i] = abs(s[i] - t[i]);

        int k(0), c(0), len(0);

        for (int i = 1; i <= s.length(); ++i) {
            c += costs[i - 1];
            while (c > maxCost)
                c -= costs[k++];
            len = max(len, i - k);
        }

        return len;
    }
};

class Solution1209 {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (const char& c: s)
            if (st.empty() || st.top().first != c)
                st.push({c, 1});
            else if (++st.top().second == k)
                st.pop();
        string ans;
        while (!st.empty()) {
            ans += string(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution1210 {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        unordered_map<int, unordered_set<int>> visited; // two cell indices
        int len(grid.size()), w(grid[0].size());
        queue<pair<int, int>> q;
        q.push({0, 1});
        int steps = 1;
        visited[0].insert(1);

        // target len * wid - 1, len * wid - 2
        // move 1: +1 +1
        // down: + wid, + wid
        // rotate clock: +0, -1 + wid
        // rotate counter: +0, - wid + 1

        int dirs[4][2] = {{1, 1}, {w, w}, {0, w - 1}, {0, 1 - w}};

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                pair<int, int> p = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int xy1 = p.first + dirs[i][0];
                    int xy2 = p.second + dirs[i][1];

                    if (xy2 - xy1 != 1 && xy2 - xy1 != w) continue;
                    if (xy1 < 0 || xy1 >= len * w || xy2 < 0 || xy2 >= len * w) continue;
                    if (visited.count(xy1) && visited[xy1].count(xy2)) continue;

                    int x1(xy1 / w), y1(xy1 % w), x2(xy2 / w), y2(xy2 % w);

                    if (x1 < 0 || x1 >= len) continue;
                    if (x2 < 0 || x2 >= len) continue;
                    if (y1 < 0 || y1 >= w) continue;
                    if (y2 < 0 || y2 >= w) continue;

                    if (grid[x1][y1] || grid[x2][y2]) continue;
                    if (i == 2 && (y2 + 1 >= w || grid[x2][y2 + 1])) continue;
                    if (i == 3 && (x2 + 1 >= len || grid[x2 + 1][y2])) continue;

                    if (xy1 == len * w - 2 && xy2 == len * w - 1) return steps;

                    q.push({xy1, xy2});
                    visited[xy1].insert(xy2);
                }
            }
            steps++;
        }

        return -1;
    }
};

class Solution1213 {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int i(0), j(0), k(0);
        vector<int> ans;
        while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) ans.push_back(arr1[i]);
            int m = min(arr1[i], min(arr2[j], arr3[k]));
            if (m == arr1[i]) i++;
            if (m == arr2[j]) j++;
            if (m == arr3[k]) k++;
        }

        return ans;
    }
};

class Solution1215 {
public:
    void bt(string& str, set<int>& ans, const string& sl, const string& sh) {
        //char c = ans.back();
        //cout << str << endl;
        if (str.back() != '0') {
            char c = str.back() - 1;
            str += c;
            bool test(str.length() == sl.length() && str >= sl || str.length() > sl.length());

            if (str.length() == sh.length()) {
                if (test && str <= sh)
                    ans.insert(stoi(str));

            } else {
                if (test)
                    ans.insert(stoi(str));
                bt(str, ans, sl, sh);
            }
            str.pop_back();
        }



        if (str.back() != '9') {
            char c = str.back() + 1;
            str += c;
            bool test(str.length() == sl.length() && str >= sl || str.length() > sl.length());

            if (str.length() == sh.length()) {
                if (test && str <= sh)
                    ans.insert(stoi(str));

            } else {
                if (test)
                    ans.insert(stoi(str));
                bt(str, ans, sl, sh);
            }
            str.pop_back();
        }
    }

    vector<int> countSteppingNumbers(int low, int high) {
        set<int> ans;
        string sl(to_string(low)), sh(to_string(high));

        for (int i = low; i < 10; ++i)
            ans.insert(i);

        for (char c = '1'; c <= '9'; ++c) {
            string str(1, c);
            bt(str, ans, sl, sh);
        }

        return vector<int>(ans.begin(), ans.end());
    }
};

class Solution1216 {
public:
    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length()));

        for (int len = 1; len <= s.length(); ++len) {
            for (int i = 0; i + len - 1 < s.length(); ++i) {
                int j = i + len - 1;
                dp[i][j] = s[i] == s[j] ? len > 2 ? dp[i+1][j-1] + 2 : j - i + 1 : max(dp[i][j-1], dp[i+1][j]);
            }
        }
        //cout << dp[0][s.length() - 1] << endl;
        return dp[0][s.length() - 1] + k >= s.length();
    }
};

class Solution1217 {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odds(0), evens(0);
        for (const int& i: chips)
            i % 2 ? odds++ : evens++;
        return min(odds, evens);
    }
};

class Solution1218 {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> rec;
        int ans(0);

        for (const int& n: arr)
            ans = max(ans, rec[n] = rec[n - difference] + 1);

        return ans;
    }
};

class Solution1219 {
public:
    int m, n;

    int ans;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    unordered_set<int> visited;

    void dfs(const vector<vector<int>>& grid, int i, int j, int& gold) {
        ans = max(ans, gold);

        for (int k = 0; k < 4; ++k) {
            int nx = i + dirs[k][0];
            int ny = j + dirs[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (!grid[nx][ny]) continue;
            if (visited.count(nx * n + ny)) continue;
            visited.insert(nx * n + ny);
            gold += grid[nx][ny];
            dfs(grid, nx, ny, gold);
            gold -= grid[nx][ny];
            visited.erase(nx * n + ny);

        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        ans = 0;
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    visited.insert(i * n + j);
                    dfs(grid, i, j, grid[i][j]);
                    visited.erase(i * n + j);
                }
            }
        }

        return ans;
    }
};

class Solution1220 {
public:
    int countVowelPermutation(int n) {
        vector<long> v(5, 1);
        while (--n) {
            long na = v[1] + v[2] + v[4];
            long ne = v[0] + v[2];
            long ni = v[1] + v[3];
            long no = v[2];
            long nu = v[2] + v[3];
            v[0] = na % 1000000007;
            v[1] = ne % 1000000007;
            v[2] = ni % 1000000007;
            v[3] = no % 1000000007;
            v[4] = nu % 1000000007;
        }

        int ans(0);
        for (const long& i : v) {
            ans += (i % 1000000007);
            ans %= 1000000007;
        }
        return ans;
    }
};

class Solution1221 {
public:
    int balancedStringSplit(string s) {
        int cnt(0), ans(0);
        for (const char& c: s) {
            c == 'L' ? cnt++ : cnt--;
            if (!cnt) ans++;
        }
        return ans;
    }
};

class Solution1222 {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // ul: up-left, u: up, ur: up-right
        // l: left, r: right
        // dl: down-left, d: down, dr: down-right

        // Time Complexity: O(n)
        // Space Complexity: O(1)

        unordered_map<string, pair<int, vector<int>>> rec;
        for (const vector<int>& queen: queens) {
            int dx(queen[0] - king[0]), dy(queen[1] - king[1]);
            if (dx == 0) {
                if (dy < 0) {
                    if (!rec.count("l") || rec["l"].first > -dy)
                        rec["l"] = {-dy, queen};
                } else {
                    if (!rec.count("r") || rec["r"].first > dy)
                        rec["r"] = {dy, queen};
                }
            } else if (dy == 0) {
                if (dx < 0) {
                    if (!rec.count("u") || rec["u"].first > -dx)
                        rec["u"] = {-dx, queen};
                } else {
                    if (!rec.count("d") || rec["d"].first > dx)
                        rec["d"] = {dx, queen};
                }
            } else if (abs(dx) == abs(dy)) {
                if (dx < 0 && dy < 0) {
                    if (!rec.count("ul") || rec["ul"].first > -dx)
                        rec["ul"] = {-dx, queen};
                } else if (dx < 0 && dy > 0) {
                    if (!rec.count("ur") || rec["ur"].first > -dx)
                        rec["ur"] = {-dx, queen};
                } else if (dx > 0 && dy < 0) {
                    if (!rec.count("dl") || rec["dl"].first > dx)
                        rec["dl"] = {dx, queen};
                } else {
                    if (!rec.count("dr") || rec["dr"].first > dx)
                        rec["dr"] = {dx, queen};
                }
            }
        }

        vector<vector<int>> ans;

        for (const auto& p: rec)
            ans.push_back(p.second.second);

        return ans;
    }
};

class Solution1224 {
public:
    int maxEqualFreq(vector<int>& nums) {
        map<int, int> freq, cnts;
        int ans(0), k(0);

        for (const int& n: nums) {

            if (cnts.count(freq[n]) && !(--cnts[freq[n]]))
                cnts.erase(freq[n]);

            cnts[++freq[n]]++;

            ++k;
            if (cnts.size() == 1) {
                ans = k - 1;
                if (cnts.count(1)) ans = k;
            } else if (cnts.size() == 2) {
                if (cnts.count(1) && cnts[1] == 1)
                    ans = k;
                else {
                    auto it = cnts.begin(), jt(next(it));
                    if (jt->first - it->first == 1 && jt->second == 1)
                        ans = k;
                }
            }

        }


        return freq.size() == 1 && freq.count(1) ? ans + 1 : ans;
    }
};

class Solution1227 {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1.0 : 0.5;
    }
};

class Solution1228 {
public:
    int missingNumber(vector<int>& arr) {
        int d(0), prev(0);
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (i && d != arr[i + 1] - arr[i])
                return abs(arr[i + 1] - arr[i]) > abs(d) ? (arr[i + 1] + arr[i]) / 2 : prev + d / 2;
            d = arr[i + 1] - arr[i];
            prev = arr[i];
        }

        return arr[0];
    }
};

class Solution1229 {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        map<int, int> rec;

        for (const vector<int>& s1: slots1) {
            rec[s1[0]]++;
            rec[s1[1]]--;
        }

        for (const vector<int>& s2: slots2) {
            rec[s2[0]]++;
            rec[s2[1]]--;
        }

        int c(0), prev(-1), temp(-1);

        for (const auto& p: rec) {
            c += p.second;
            if (c == 2)
                temp = p.first;
            else if (prev == 2 && temp != -1) {
                if (p.first - temp >= duration)
                    return {temp, temp + duration};
                temp = -1;
            }
            prev = c;
        }

        return {};
    }
};

class Solution1230 {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        double dp[prob.size() + 1][target + 1] = {1};

        for (int i = 1; i <= prob.size(); ++i)
            for (int j = 0; j <= target; ++j)
                dp[i][j] = (j ? dp[i-1][j-1] * prob[i-1] : 0) + dp[i-1][j] * (1 - prob[i-1]);

        return dp[prob.size()][target];
    }
};

class Solution1231 {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int i = 1;
        int j = 1e9 / (K ? K : 1);

        while (i < j) {
            int m = i + (j - i + 1) / 2;
            int cuts(0), sum(0);
            for (const int& s: sweetness) {
                if ((sum += s) >= m) {
                    sum = 0;
                    if (++cuts > K) break;
                }

            }
            cuts > K ? i = m : j = m - 1;
        }

        return i;
    }
};

class Solution1233 {
public:
    bool compare(const string& s, const string& t) {
        if (s.length() >= t.length())
            return true;
        for (int i = 0; i < s.length(); ++i)
            if (s[i] != t[i])
                return true;
        return t[s.length()] != '/';
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;

        for (const string& s: folder)
            if (ans.empty() || compare(ans.back(), s))
                ans.push_back(s);

        return ans;
    }
};

class Solution1234 {
public:
    int balancedString(string s) {
        int i(0), ans(s.length()), c(s.length()/4);
        unordered_map<char, int> m;

        for (char c: s) m[c]++;

        for (int j = 0; j < s.length(); ++j) {
            m[s[j]]--;
            while (i < s.length() && m['Q'] <= c && m['W'] <= c && m['E'] <= c && m['R'] <= c) {
                ans = min(ans, j-i+1);
                m[s[i++]]++;
            }
        }

        return ans;
    }
};

class Solution1235 {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n(profit.size());
        vector<vector<int>> v(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            v[i][0] = endTime[i];
            v[i][1] = startTime[i];
            v[i][2] = profit[i];
        }

        sort(v.begin(), v.end());
        vector<vector<int>> dp = {{0, 0}}; //init state: endTime(0), profit(0)

        for (const vector<int>& task: v) {

            auto it = --lower_bound(dp.begin(), dp.end(), task, [](const vector<int>& a, const vector<int>& b) {return a[0] <= b[1];});
            int curr = (*it)[1] + task[2];
            if (curr > dp.back()[1])
                dp.push_back({task[0], curr});
        }
        return dp.back()[1];
    }
};

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution1236 {
public:

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        queue<string> q; // bfs
        unordered_set<string> visited = {startUrl};
        auto it = startUrl.find('/', 7) == string::npos ? startUrl.end() : startUrl.begin() + startUrl.find('/', 7);
        string hostname(startUrl.begin() + startUrl.find('.') + 1, it);
        q.push(startUrl);

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                string url = q.front();
                q.pop();

                vector<string> suburls = htmlParser.getUrls(url);

                for (const string& suburl: suburls)
                    if (!visited.count(suburl))
                        if (suburl.find(hostname) != string::npos) {
                            visited.insert(suburl);
                            q.push(suburl);
                        }
            }
        }

        return vector<string>(visited.begin(), visited.end());
    }
};

class Solution1238 {
public:
    vector<int> circularPermutation(int n, int start) {
        int loc(0);
        vector<int> ans = {0};
        for (int i = 0; i < n; ++i) {
            ans.insert(ans.end(), ans.rbegin(), ans.rend());
            for (int j = ans.size() / 2; j < ans.size(); ++j) {
                ans[j] += (1 << i);
                if (ans[j] == start) loc = j;
            }
        }
        rotate(ans.begin(), ans.begin() + loc, ans.end());
        return ans;
    }
};

class Solution1239 {
public:
    void concatenate(const vector<int>& bits, int curr, int c, int& ans) {
        bool test(true);
        for (int i = curr; i < bits.size(); ++i) {
            int temp = c ^ bits[i];

            if ((temp & c) == c && (temp & bits[i]) == bits[i]) {
                test = false;
                concatenate(bits, i + 1, temp, ans);
            }
        }


        if (test) {
            int k(0);
            while (c) {
                k += c & 1;
                c >>= 1;
            }
            ans = max(ans, k);
        }

    }
    int maxLength(vector<string>& arr) {
        vector<int> bits(arr.size());
        int k(arr.size());
        int j(0);

        for (const string& str: arr) {
            vector<bool> letters(26, false);
            bool finished(true);

            for (const char& c: str) {
                if (letters[c - 'a']) {
                    k--;
                    finished = false;
                    break;
                } else
                    letters[c - 'a'] = true;
            }

            if (finished) {
                for (int i = 0; i < 26; ++i)
                    if (letters[i])
                        bits[j] += 1 << i;
                j++;
            }

        }

        bits.resize(k);
        int ans(0);
        concatenate(bits, 0, 0, ans);

        return ans;
    }
};

class Solution1240 {
public:
	int tilingRectangle(int n, int m) {
		if (n == m) return 1;
		if (n > m) swap(n, m);
		int heights[n] = {};

		int dp[n + 1][m + 1] = {};

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++){
				if (i == j) {
					dp[i][j] = 1;
					continue;
				}
				dp[i][j] = i * j;
				for (int k = 1; k <= i / 2; k++)
					dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j]);
				for (int k = 1; k <= j / 2; k++)
					dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k]);
			}

		int res(dp[n][m]);
		dfs(n, m, heights, 0, res);
		return res;
	}

	void dfs(const int& n, const int& m, int heights[], int cnt, int& res) {
		if (cnt >= res) return;

		int left(0), min_height(m);
		for (int i = 0; i < n; i++)
			if (heights[i] < min_height)
				min_height = heights[left = i];

		if (min_height == m) {
			res = min(cnt, res);
			return;
		}

		int right(left);
		while (right < n && heights[left] == heights[right] && right - left + min_height < m) right++;

		for (int i = right; i > left; --i) {
			for (int j = left; j < i; ++j)
				heights[j] += i - left;
			dfs(n, m, heights, cnt + 1, res);
			for (int j = left; j < i; ++j)
				heights[j] -= i - left;
		}

	}
};

class Solution1243 {
public:
    vector<int> transformArray(vector<int>& arr) {
        while (true) {
            vector<int> temp(arr);

            bool unchanged(true);
            for (int i = 1; i < arr.size() - 1; ++i)
                if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                    temp[i]++;
                    unchanged = false;
                } else if (arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                    temp[i]--;
                    unchanged = false;
                }
            if (unchanged) break;

            bool equal(true);
            for (int i = 1; i < arr.size() - 2; ++i)
                if (arr[i] != arr[i+1])
                    equal = false;
            if (equal) break;

            arr = temp;
        }

        return arr;
    }
};

// 1244
class Leaderboard {
public:
    map<int, int> board;
    unordered_map<int, int> players;
    Leaderboard() {

    }

    void addScore(int playerId, int score) {
        if (players.count(playerId))
            if (!(--board[players[playerId]]))
                board.erase(players[playerId]);
        players[playerId] += score;
        board[players[playerId]]++;
    }

    int top(int K) {
        int sum(0);
        auto it = board.end();
        while (true) {
            --it;
            sum += it->first * min(it->second, K);
            if ((K -= it->second) <= 0 || it == board.begin()) break;
        }
        return sum;
    }

    void reset(int playerId) {
        if (!(--board[players[playerId]]))
            board.erase(players[playerId]);
        players[playerId] = 0;
    }
};

class Solution1245 {
public:
    void dfs(map<int, set<int>>& rec, int curr, unordered_set<int>& path, int& res) {
        bool ne(true);

        for (int e: rec[curr]) {
            if (path.count(e)) continue;
            ne = false;
            path.insert(e);
            dfs(rec, e, path, res);
            path.erase(e);
        }

        if (ne) res = max(res, (int)path.size());
    }

    int treeDiameter(vector<vector<int>>& edges) {
        // O(E) Complexity
        map<int, set<int>> rec;
        for (vector<int>& edge: edges) {
            rec[edge[0]].insert(edge[1]);
            rec[edge[1]].insert(edge[0]);
        }

        int res(0), node(-1);

        unordered_set<int> path;

        auto it = rec.begin();

        dfs(rec, it->first, path, res, node);
        dfs(rec, rec[node]->first, path, res, node);

        return res - 1;
    }
};

class Solution1246 {
public:

    int minimumMoves(vector<int>& arr) {
        int n(arr.size());

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // edge case 1: every single letter takes one step to remove
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        // edge case 2: two consecutive letter takes one step to remove if same else two steps

        for (int i = 0; i < n - 1; ++i)
            dp[i][i+1] = arr[i] == arr[i+1] ? 1 : 2;

        for (int len = 3; len <= n; len++) {
            for (int i = 0, j = i + len - 1; j < n; i++, j++) {
                if (arr[i] == arr[j])
                    dp[i][j] = dp[i+1][j-1];
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
            }
        }

        return dp[0][n-1];
    }
};

class Solution1247 {
public:
    int minimumSwap(string s1, string s2) {
        int x1(0), y1(0), x2(0), y2(0);
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] == s2[i]) continue;
            s1[i] == 'x' ? x1++ : y1++;
            s2[i] == 'x' ? x2++ : y2++;
        }

        return (x1 + x2) % 2 || (y1 + y2) % 2 ? -1 : x1 / 2 + y1 / 2 + (x1 % 2) * 2;
    }
};

class Solution1248 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i(0), ans(0), c(0);
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] % 2) c++;
            if (c == k) {
                int t1(i), t2(j);
                while (nums[i++] % 2 == 0) {};
                while (++j < nums.size() && nums[j] % 2 == 0) {}
                ans += (i - t1) * ((j--) - t2);
                c--;
            }
        }

        return ans;
    }
};

class Solution1249 {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st1, st2;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                st1.push(i);
            else if (s[i] == ')')
                st1.empty() ? st2.push(i) : st1.pop();
        }

        while (!st1.empty() || !st2.empty()) {
            int a = st1.empty() ? -1 : st1.top();
            int b = st2.empty() ? -1 : st2.top();
            if (a > b) {
                s.erase(s.begin() + a);
                st1.pop();
            } else if (b > a) {
                s.erase(s.begin() + b);
                st2.pop();
            }
        }

        return s;
    }
};

class Solution1250 {
public:
    bool isGoodArray(vector<int>& nums) {
        int g(nums[0]);
        for (const int& n: nums)
            if ((g = gcd(g, n)) == 1)
                return true;
        return false;
    }
};
