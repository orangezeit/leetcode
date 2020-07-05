/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int zmax = 0;
    int z(TreeNode* root,int c, char dir){
        return (dir=='l') ? (root->left ? z(root->left,c+1,'r') : c) : ((root->right != NULL) ? z(root->right,c+1,'l') : c);
    }
    int zz(TreeNode* root, int mark){
        int lc = mark >= 0 ? z(root,0,'l') : 0;
        int rc = mark <= 0 ? z(root,0,'r') : 0;
        //cout << lc << " " << rc << endl;
        return max(lc,rc);
    }
    void po(TreeNode* root, int mark=0){
        if(root != NULL){
            int zc = zz(root, mark);
            //cout << zc << endl;
            zmax = max(zmax,zc);
            po(root->left, 1);
            po(root->right, -1);
        }
    }
    int longestZigZag(TreeNode* root) {
        po(root);
        return zmax;
    }
};
