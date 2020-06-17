class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> v = {1};
        while (v.size() < N) {
            vector<int> temp;
            for (const int& i: v)
                if (i * 2 - 1 <= N)
                    temp.push_back(i * 2 - 1);
            for (const int& i: v)
                if (i * 2 <= N)
                    temp.push_back(i * 2);
            v = temp;
        }
        return v;
    }
};
