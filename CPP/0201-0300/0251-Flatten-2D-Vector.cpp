class Vector2D {
public:
    vector<int> vec;
    int k = 0;
    
    Vector2D(vector<vector<int>>& v) {
        for (const vector<int>& row: v)
            vec.insert(vec.end(), row.begin(), row.end());
    }
    
    int next() {
        return vec[k++];
    }
    
    bool hasNext() {
        return k < vec.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
