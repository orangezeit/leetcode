class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int root(INT_MIN);
        for (int i = 0; i < preorder.size(); ++i) {
            if (preorder[i] < root) return false;
            while (!s.empty() && s.top() < preorder[i]) {
               
                root = s.top();
                s.pop();
                
            }
            s.push(preorder[i]);
        }
        
        return true;
    }
};
