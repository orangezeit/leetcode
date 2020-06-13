// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    queue<char> bf;
    int read(char *buf, int n) {
        int k(0), c;
        for (int i = 0; i < n && !bf.empty(); ++i) {
            buf[k++] = bf.front();
            bf.pop();
        }
        
        char* temp = new char[4];
        while(c = read4(temp)) {
            
            int x(min(c, n - k));
            
            for (int i = 0; i < x; ++i)
                buf[k++] = temp[i];
            for (int i = x; i < c; ++i)
                bf.push(temp[i]);
        }
        return min(k, n);
    }
};
