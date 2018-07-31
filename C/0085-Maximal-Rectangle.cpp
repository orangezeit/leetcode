// Method 1
private:
    bool check(vector<vector<char>>& matrix, int x, int y, int l, int w) {
        for (int i = x; i < x + l; ++i) {
            for (int j = y; j < y + w; ++j) {
                if (matrix[i][j] == '0') return false;
            }
        }
        
        return true;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l <= m - i; ++l) {
                    for (int w = 0; w <= n - j; ++w) {
                        if (check(matrix, i, j, l, w)) {
                            s = max(s, l * w);
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        
        return s;
    }
    
// Method 2
private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s; // indices
        s.push(0);
        heights.push_back(-1);
        int i = 1;
        int area = 0;
        
         while (!s.empty()) {
            while (heights[s.top()] > heights[i]) {
                int h = heights[s.top()];
                s.pop();
                if (s.empty()) {
                    area = max(area, h * i);
                    break;
                } else {
                    area = max(area, h * (i - s.top() - 1));
                }
            }
            
            if (i < heights.size() - 1) s.push(i++);
        }
        heights.pop_back();
        return area;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        vector<int> heights(matrix[0].size(), 0);
        int area = 0;
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] - '0'? heights[j]++ : heights[j] = 0;
            }
            area = max(area, largestRectangleArea(heights));
        }
        
        return area;
    }
