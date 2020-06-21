class Solution {
public:
    string strWithout3a3b(int A, int B) {
        char ca('a'), cb('b');

        if (A < B) {
            swap(A, B);
            swap(ca, cb);
        }

        string str;

        while (A) {
            str += ca;
            A--;

            if (A > B) {
                str += ca;
                A--;
            }

            if (B) {
                str += cb;
                B--;
            }
        }

        return str;
    }
};
