private:
    vector<bool> visited;
public:
    void arrangeHelper(int& c, int s, int N) {
        if (s == N) {
            c++;
        } else {
            for (int i = 0; i < N; ++i) {
                if (!visited[i]) {
                    if ((i+1) % (s+1) == 0 || (s+1) % (i+1) == 0) {
                        visited[i] = true;
                        arrangeHelper(c, s+1, N);
                        visited[i] = false;
                    }
                }
            }
        }
    }
    
    int countArrangement(int N) {
        visited = vector<bool>(N, false);
        int c = 0; 
        arrangeHelper(c, 0, N);
        return c;
    }
