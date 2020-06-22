/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(const vector<vector<int>>& grid, const int& xl, const int& xr, const int& yl, const int& yr) {
        for (int i = xl; i < xr; ++i)
            for (int j = yl; j < yr; ++j)
                if (grid[i][j] != grid[xl][yl]) {
                    const int xm((xl + xr) / 2), ym((yl + yr) / 2);
                    return new Node(0, false, construct(grid, xl, xm, yl, ym),
                                              construct(grid, xl, xm, ym, yr),
                                              construct(grid, xm, xr, yl, ym),
                                              construct(grid, xm, xr, ym, yr));
                }
        return new Node(grid[xl][yl], true);
    }

    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, grid.size(), 0, grid.size());
    }
};
