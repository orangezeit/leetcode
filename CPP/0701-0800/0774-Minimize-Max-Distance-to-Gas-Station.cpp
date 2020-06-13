class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int n(stations.size());
        const double eps(1e-6);
        double left(0), right(stations[n-1] - stations[0]), mid;
        while (left + eps < right) {
            mid = (left + right) / 2;
            int cnt(0);
            for (int i = 0; i < n - 1; ++i)
                cnt += ceil((stations[i+1] - stations[i]) / mid) - 1;
            cnt > K ? left = mid : right = mid;
        }
        return mid;
    }
};
