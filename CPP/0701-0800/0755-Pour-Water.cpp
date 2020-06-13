class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        //O(VK)
        for (int i = 0; i < V; ++i) {
            //bool found(false);
            int temp(-1);

            for (int i = K; i >= 1; --i) {
                if (heights[i-1] < heights[i]) {
                    //found = true;
                    temp = i - 1;
                    //heights[i-1]++;
                    //break;
                } else if (heights[i-1] > heights[i]) {
                    break;
                }
            }

            if (temp >= 0) {
                heights[temp]++;
                continue;
            }

            for (int i = K; i < heights.size() - 1; ++i) {
                if (heights[i+1] < heights[i]) {
                    temp = i + 1;
                } else if (heights[i+1] > heights[i]) {
                    break;
                }
            }
            if (temp >= 0) {
                heights[temp]++;
                continue;
            }
            heights[K]++;
        }

        return heights;
    }
};
