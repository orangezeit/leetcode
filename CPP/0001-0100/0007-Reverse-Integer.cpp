class Solution {
public:
    int reverse(int x) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        string str(to_string(x));
        reverse(str.begin(), str.end());
        if (x < 0) str.pop_back();
        return str.length() < 10 || str <= "2147483647" ? (x < 0 ? -1 : 1) * stoi(str) : 0;
    }
};
