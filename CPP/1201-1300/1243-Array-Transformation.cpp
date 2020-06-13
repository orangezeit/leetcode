class Solution {
public:
    bool unequal(vector<int>& arr) {
        //bool unequal(false);
        for (int i = 1; i < arr.size() - 2; ++i) {
            if (arr[i] != arr[i+1]) return true;

        }
        return false;
    }
    vector<int> transformArray(vector<int>& arr) {
        while (unequal(arr)) {
            vector<int> temp(arr);
            bool unchanged(true);
            for (int i = 1; i <= arr.size() - 2; ++i) {
                if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                    temp[i]++;
                    unchanged = false;
                } else if (arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                    temp[i]--;
                    unchanged = false;
                }
            }

            if (unchanged) break;
            arr = temp;
            /*
            for (int i = 0; i < arr.size(); ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;*/
        }
        return arr;
    }
};
