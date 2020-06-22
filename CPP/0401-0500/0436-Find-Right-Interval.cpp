/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    //O(nlgn)
    vector<pair<Interval, int>> mergeSort(vector<pair<Interval, int>> intervals) {
        int n = intervals.size();

        if (n == 1) {
            return intervals;
        } else if (n == 2) {
            if (intervals[0].first.start > intervals[1].first.start) {
                swap(intervals[0], intervals[1]);
            }
            return intervals;
        } else {

            vector<pair<Interval, int>> left(intervals.begin(), intervals.begin() + n/2);
            vector<pair<Interval, int>> right(intervals.begin() + n/2, intervals.end());

            left = mergeSort(left);
            right = mergeSort(right);

            int l(0), r(0), k(0);

            while (l != n/2 && r != n-n/2) {
                if (left[l].first.start < right[r].first.start) {
                    intervals[k] = left[l];
                    l++;
                } else {
                    intervals[k] = right[r];
                    r++;
                }
                k++;
            }

            if (l == n/2) {
                while (r != n-n/2) {
                    intervals[k] = right[r];
                    r++;
                    k++;
                }
            } else {
                while (l != n/2) {
                    intervals[k] = left[l];
                    l++;
                    k++;
                }
            }

            return intervals;
        }
    }

    vector<int> findRightInterval(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<pair<Interval, int>> intervals_copy(n);

        for (int i = 0; i < n; ++i) {
            intervals_copy[i].first = intervals[i];
            intervals_copy[i].second = i;
        }

        intervals_copy = mergeSort(intervals_copy); //O(nlgn)

        vector<int> ans(n);
        int l, r, m;
        bool enter;

        for (int i = 0; i < n; ++i) {
            l = 0;
            r = n - 1;
            enter = false;

            while (r-l > 1) {
                m = (l+r)/2;

                if (intervals_copy[m].first.start < intervals[i].end) {
                    l = m + 1;
                } else if (intervals_copy[m].first.start > intervals[i].end) {
                    r = m;
                } else {
                    ans[i] = intervals_copy[m].second;
                    enter = true;
                    break;
                }
            }

            if (!enter) {
                if (intervals[i].end > intervals_copy[r].first.start) {
                    ans[i] = -1;
                } else if (intervals[i].end > intervals_copy[l].first.start) {
                    ans[i] = intervals_copy[r].second;
                } else {
                    ans[i] = intervals_copy[l].second;
                }
            }
        }

        return ans;
    }
};
