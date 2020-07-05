class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> balloon(5); // a 1 b 1 l 2 n 1 o 2
        int ans(INT_MAX);
        for (const char& c: text) {
            switch (c) {
                case 'a': balloon[0]++; break;
                case 'b': balloon[1]++; break;
                case 'l': balloon[2]++; break;
                case 'n': balloon[3]++; break;
                case 'o': balloon[4]++;
            }
        }
        balloon[2] /= 2;
        balloon[4] /= 2;

        for (int i = 0; i < 5; ++i) {
            //cout << balloon[i] << endl;
            ans = min(ans, balloon[i]);
        }

        return ans;
    }
};
