class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {

        unordered_map<string, int> record;
        unordered_set<string> answer;
        int sum(INT_MAX);

        for (int i = 0; i < list1.size(); ++i) {
            record[list1[i]] = i;
        }

        for (int i = 0; i < list2.size(); ++i) {
            if (record.find(list2[i]) != record.end()) {
                if (i + record.find(list2[i])->second == sum) {
                    answer.insert(list2[i]);
                    sum = i + record.find(list2[i])->second;
                } else if (i + record.find(list2[i])->second < sum) {
                    answer.clear();
                    answer.insert(list2[i]);
                    sum = i + record.find(list2[i])->second;
                }
            }
        }

        return vector<string>(answer.begin(), answer.end());
    }
};
