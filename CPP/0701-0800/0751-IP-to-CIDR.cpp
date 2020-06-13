class Solution {
public:
    string CIDR(long x, int count) {
        string ans;
        vector<string> nums(4, "0");
        int len(0), k(3);

        while (x) {
            nums[k--] = to_string(x & 255);
            x >>= 8;
        }
        k = -1;
        while (k < 3) {
            ans += nums[++k];
            ans += '.';
        }

        ans.back() = '/';

        while (count>>len)
            len++;

        return ans + to_string(33 - len);
    }

    vector<string> ipToCIDR(string ip, int n) {
        long x = 0;
        ip += '.';
        int k(0);

        for (int i = 0; i < ip.length(); ++i) {
            if (ip[i] == '.') {
                x <<= 8;
                x += stoi(ip.substr(k, i-k));
                k = i+1;
            }
        }

        vector<string> ans;

        while (n) {
            int count = x & -x;

            while (count > n)
                count /= 2;

            ans.push_back(CIDR(x, count));

            n -= count;
            x += count;
        }

        return ans;
    }
};
