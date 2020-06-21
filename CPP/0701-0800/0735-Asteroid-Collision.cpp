class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;

        for (int i = 0; i < asteroids.size(); ++i) {
            if (s.empty()) {
                s.push_back(asteroids[i]);
            } else if (s.back() > 0 && asteroids[i] < 0) {
                int sum = s.back() + asteroids[i];

                if (sum < 0) {
                    s.pop_back();
                    --i;
                } else if (sum == 0) {
                    s.pop_back();
                }

            } else {
                s.push_back(asteroids[i]);
            }
        }

        return s;
    }
};
