class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> three;
        for (const int& i: nums) {
            three.insert(i);
            if (three.size() > 3)
                three.erase(three.begin());
        }
        return three.size() == 3 ? *three.begin() : *three.rbegin();
    }
};
