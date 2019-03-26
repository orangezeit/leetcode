private:
    int m, n;
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool isValid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
    void fill(vector<vector<int>>& image, int x, int y, const int& oc, const int& nc) {
        image[x][y] = nc;
        
        for (int i = 0; i < 4; ++i) {
            if (isValid(x + d[i][0], y + d[i][1]) && image[x + d[i][0]][y + d[i][1]] == oc) {
                fill(image, x + d[i][0], y + d[i][1], oc, nc);
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor != newColor) fill(image, sr, sc, oldColor, newColor);
        
        return image;
    }
