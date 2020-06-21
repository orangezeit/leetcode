class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_set<int> collected;
        int cnt = 0;

        for (int i = 0; i < arr.size(); ++i) {
            collected.insert(arr[i]);
            for (int j = 0; j <= i; ++j) {
                if (collected.find(j) == collected.end()) {
                    break;
                }
                if (j == i) {
                    cnt++;
                }
            }
        }


        return cnt;
    }
};
