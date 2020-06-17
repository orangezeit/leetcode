class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> rec;
        int largest(0);

        for (int i = 0; i < values.size(); ++i) {
            pq.push({values[i], labels[i]});
        }

        while (!pq.empty() && num_wanted) {
            int label = pq.top().second;

            if (rec[label] != use_limit) {
                largest += pq.top().first;
                rec[label]++;
                num_wanted--;
            }

            pq.pop();
        }

        return largest;
    }
};
