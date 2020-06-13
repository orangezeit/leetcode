    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        
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
        
        return area;
    }
