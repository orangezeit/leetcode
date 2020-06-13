class Solution {
public:
    int minSwaps(vector<int>& data) {
        int cnt(0);

        for (const int& n: data)
            cnt += n;

        int temp(0);

        for (int i = 0; i < cnt; ++i)
            temp += data[i];

        int ans(cnt - temp);

        for (int i = cnt; i < data.size(); ++i) {
            temp += data[i] - data[i - cnt];
            ans = min(ans, cnt - temp);
        }

        return ans;
    }
};
