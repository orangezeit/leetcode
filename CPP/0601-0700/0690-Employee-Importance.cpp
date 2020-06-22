/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, pair<int, vector<int>>> rec;
        for (const auto& e: employees) {
            rec[e->id] = {e->importance, e->subordinates};
        }

        int score(rec[id].first);
        queue<int> q;
        q.push(id);

        while (!q.empty()) {
            int s = q.size();

            while (s--) {

                int person = q.front();
                q.pop();
                for (const int& p: rec[person].second) {
                    score += rec[p].first;
                    q.push(p);
                }
            }
        }

        return score;
    }
};
