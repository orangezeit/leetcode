class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        vector<int> hs, vs;
        int mx(0), mod(1e9 + 7);
        for (int i = 0; i < hc.size(); ++i) {
            hs.emplace_back(hc[i] - mx);
            mx = hc[i];
        }
        hs.emplace_back(h - mx);
        mx = 0;
        for (int i = 0; i < vc.size(); ++i) {
            vs.emplace_back(vc[i] - mx);
            mx = vc[i];
        }
        vs.emplace_back(w - mx);
        sort(hs.begin(), hs.end());
        sort(vs.begin(), vs.end());
        return (long long) hs.back() * vs.back() % mod;
    }
};
