    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        // Method 1
        // Time Complexity: O(n^3)
        // Space Complexity: O(1)
        
        if (points.size() < 3) {
            return 0;
        }
        
        int num = 0;
        int a, b, c;
        
        for (int i = 0; i < points.size()-2; ++i) {
            for (int j = i+1; j < points.size()-1; ++j) {
                for (int k = j+1; k < points.size(); ++k) {
                    a = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
                    b = (points[i].first - points[k].first) * (points[i].first - points[k].first) + (points[i].second - points[k].second) * (points[i].second - points[k].second);
                    c = (points[j].first - points[k].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
                    if (a == b) {
                        num += 2;
                    } else if (a == c) {
                        num += 2;
                    } else (b == c) {
                        num += 2;
                    }
                }
            }
        }
        
        return num;
        
        // Method 2
        // Time Complexity: O(n^2)
        // Space Complexity: O(n)
        
        int num(0), d;
        
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> record;
            for (int j = 0; j < points.size(); ++j) {
                d = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
                record[d]++;
            }
            for (auto it = record.begin(); it != record.end(); ++it) {
                num += it->second * (it->second - 1);
            }
        }
        
        return num;
    }
