class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int i(0), j(0), k(0);
        vector<int> ans;
        while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                ans.push_back(arr1[i]);
            }

                int m = min(arr1[i], min(arr2[j], arr3[k]));
                if (m == arr1[i]) i++;
                if (m == arr2[j]) j++;
                if (m == arr3[k]) k++;
        }

        return ans;
    }
};
