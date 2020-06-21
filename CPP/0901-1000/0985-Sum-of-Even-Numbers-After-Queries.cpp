class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> sum_query(queries.size());
        int even_sum = 0;

        for (const int& i: A) {
            if (i % 2 == 0)
                even_sum += i;
        }

        for (int i = 0; i < queries.size(); ++i) {
            if (abs(A[queries[i][1]]) % 2) { // odd
                if (abs(queries[i][0]) % 2)
                    even_sum += (A[queries[i][1]] + queries[i][0]);
            } else { // even
                abs(queries[i][0]) % 2 ? even_sum -= A[queries[i][1]] : even_sum += queries[i][0];
            }
            //cout << even_sum << endl;
            A[queries[i][1]] += queries[i][0];
            sum_query[i] = even_sum;
        }

        return sum_query;
    }
};
