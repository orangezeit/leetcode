class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string C(A);
        int a(A.length()), b(B.length()), t(b / a + 1);
        while (t) {
            if (t % 2) A += C;
            C += C;
            t /= 2;
        }
        auto found = A.find(B);
        return found == string::npos ? -1 : ceil((found + b) * 1.0 / a);
    }
};
