class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int length = s.length();
        string result(length, 0);

        for(int i = 0; i < length; i++)
            result[indices[i]] = s[i];
        return result;
    }
};
