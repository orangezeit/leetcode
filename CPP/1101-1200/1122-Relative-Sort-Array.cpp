class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> m;
        for (int i = 0; i < arr2.size(); ++i)
            m[arr2[i]] = i - arr2.size();
        sort(arr1.begin(), arr1.end(),
             [&](const int& x, const int& y){
                 return m[x] < m[y] || m[x] == m[y] && x < y;
             });
        return arr1;
    }
};
