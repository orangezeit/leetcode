class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> bag(stones.begin(), stones.end());

        while (bag.size() > 1) {
            int temp = bag.top();
            bag.pop();
            if (temp == bag.top()) {
                bag.pop();
            } else {

                int temp2 = temp - bag.top();
                bag.pop();
                bag.push(temp2);
            }
        }

        return bag.empty() ? 0 : bag.top();
    }
};
