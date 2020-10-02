class Solution {
public:
    int minFlips(string target) {
        int ans(target[0] == '1');
        for (int i = 1; i < target.length(); ++i)
            if (target[i - 1] != target[i])
                ans++;
        return ans;
    }
};
