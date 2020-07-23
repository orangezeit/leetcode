class Solution {
public:
    int getCnt(long sums[], int n, int x) {
        int res = 0;
        for(int i = 0, p = 1; i < n; ++i) {
            while(p <= n && sums[p] - sums[i] <= x)
                ++p;
            res += p-1-i;
        }
        return res;
    }
    int getKth(long sums[], int n, int idx) {
        int l = 0, r = 1e5;
        while(l < r) {
            int mid = (l + r) / 2, cnt = getCnt(sums, n, mid);
            if(cnt < idx)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    long F(long sums[], long ssums[], int n, int x) {
        long num = getKth(sums, n, x), res = 0, cnt = 0;
        for(int i = 0, p = 1; i < n; ++i) {
            while(p <= n && sums[p] - sums[i] < num)
                ++p;
            // res = ssums[b] - ssums[a-1] + (b-a+1)*sums[m-1]
            //     = ssums[(p-1)] - ssums[(i+1)-1] - (((p-1)-(i+1))+1)*sums[(i+1)-1]
            //     = ssums[p-1] - ssums[i] - (p-i-1)*sums[i].
            res += ssums[p-1] - ssums[i] - sums[i] * ((long)(p-1-i));
            cnt += p-1-i;
        }
        return res + (x-cnt)*num;
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long sums[n+1], ssums[n+1];
        sums[0] = ssums[0] = 0;
        for(int i = 0; i < n; ++i) {
            sums[i+1] = sums[i] + nums[i];
            ssums[i+1] = ssums[i] + sums[i+1];
        }

        return (F(sums, ssums, n, right) - F(sums, ssums, n, left-1)) % ((long)(1e9 + 7));
    }
};
