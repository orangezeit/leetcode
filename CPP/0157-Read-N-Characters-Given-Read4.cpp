// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int c(0), s(0), k(0);
        char* temp = new char[4];
        while(c = read4(temp)) {
            for (int i = 0; i < c; ++i)
                buf[k++] = temp[i];
            s += c;
        }
        return min(s, n);
    }
};
