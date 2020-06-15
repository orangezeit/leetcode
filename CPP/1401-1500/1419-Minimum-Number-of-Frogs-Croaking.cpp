class Solution {
public:
    int minNumberOfFrogs(string cof) {
        if (cof.length() % 5) return -1;

        vector<int> croak(5); // nums of croak

        int ans(0);
        for (const char& c: cof) {
            if (c == 'c') {
                croak[0]++;
                ans = max(ans, croak[0] + croak[1] + croak[2] + croak[3]);
            } else {
                int i = c == 'r' ? 0 : c == 'o' ? 1 : c == 'a' ? 2 : 3;
                if (croak[i]--)
                    croak[i + 1]++;
                else
                    return -1;
            }
        }

        return ans;
    }
};
