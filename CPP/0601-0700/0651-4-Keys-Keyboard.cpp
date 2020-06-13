class Solution {
public:
    //unordered_map<int, int> record;

    int maxA(int N) {

        vector<int> record(N + 1, 0);

        for (int i = 0; i <= N; ++i) {
            if (i <= 3) {
                record[i] = i;
            } else {
                int k = i;

                for (int j = 3; j < i; ++j) {
                    k = max(k, record[i - j] * (j - 1));
                }

                record[i] = k;
            }
            //cout << record[i] << endl;
        }

        return record.back();
    }
};
