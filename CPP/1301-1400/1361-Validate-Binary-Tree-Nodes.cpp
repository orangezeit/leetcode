class Solution {
public:
    int traverse(int root, const vector<int>& leftChild, const vector<int>& rightChild, vector<int>& visited, bool& verified) {
        if (root == -1 || !verified) return 0;
        if (visited[root]) {
            verified = false;
            return 0;
        }
        visited[root] = 1;
        return traverse(leftChild[root], leftChild, rightChild, visited, verified) +
               traverse(rightChild[root], leftChild, rightChild, visited, verified) + 1;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> nodes(n), visited(n);
        int root(-1);
        bool verified(true);

        // mark nodes that are not roots
        for (const int& c: leftChild) if (c >= 0) nodes[c] = 1;
        for (const int& c: rightChild) if (c >= 0) nodes[c] = 1;

        for (int i = 0; i < n; ++i)
            if (!nodes[i]) {
                // more than one root
                if (root != -1) return false;
                root = i;
            }

        // if no root, return false
        if (root == -1) return false;

        // dfs, traverse from the only root
        // make sure there is no cycle or collusion
        // and the number of nodes should be n
        int c(traverse(root, leftChild, rightChild, visited, verified));

        return verified && c == n;
    }
};
