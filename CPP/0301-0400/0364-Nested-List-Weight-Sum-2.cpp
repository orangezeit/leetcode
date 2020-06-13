/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        queue<pair<NestedInteger, int>> q;
        unordered_map<int, int> record;
        int sum = 0;
        int depth = 0;

        for (int i = 0; i < nestedList.size(); ++i) {
            if(nestedList[i].isInteger()) {
                record[0] += nestedList[i].getInteger();
            } else {
                q.push({nestedList[i], 1});
            }
        }

        while (!q.empty()) {
            vector<NestedInteger> vec = q.front().first.getList();
            int level = q.front().second;
            depth = max(depth, level);

            q.pop();
            for (int i = 0; i < vec.size(); ++i) {
                if(vec[i].isInteger()) {
                    record[level] += vec[i].getInteger();
                } else {
                    q.push({vec[i], level + 1});
                }
            }
        }
        depth++;
        //cout << depth << endl;
        for (auto it = record.begin(); it != record.end(); ++it) {
            sum += it->second * (depth - it->first);
        }
        return sum;
    }
};
