#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

/*  64 Questions
    94[144, 145], 96, 98, 100, 101, 102[103, 107], 104[111], 105[106, 889, 1008],
     108, 110, 112[113, 437], 114
    124, 129, 199, 226, 230, 235, 236, 250, 257, 366, 404, 450[700, 701], 501, 508, 515, 530, 543, 563
    572, 606, 617, 637, 653, 654[998], 663, 669, 671, 814, 872, 897
    951, 958, 965, 979, 988, 993, 1022, 1026, 1104 */

struct TreeNode { // binary tree node
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node { // n-ary tree node
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

/// 0094, 0144, 0145 pre-order, in-order, postorder traversals

void orderHelper(TreeNode* root, vector<int>& vals, const string& str) {
    if (!root) return;
    if (str == "pre") vals.push_back(root->val);
    orderHelper(root->left, vals);
    if (str == "in") vals.push_back(root->val);
    orderHelper(root->right, vals);
    if (str == "post") vals.push_back(root->val);
}

vector<int> orderTraversal(TreeNode* root, const string& str) {
    // str: "pre", "in", "post"
    vector<int> vals;
    orderHelper(root, vals, str);
    return vals;
}

/// 0096

int numTrees(const int& n) {
    long ans(1);
    for (int i = 1; i <= n; ++i)
        ans = ans * (i + n) / i;
    return ans / (n + 1);
}

/// 0098

bool isValidBST(TreeNode* root) {
    vector<int> vals;
    orderHelper(root, vals, "in");
    for (int i = 1; i < vals.size(); ++i)
        if (vals[i - 1] >= vals[i])
            return false;
    return true;
}

/// 0104, 0111
int maxDepth(TreeNode* root) {
    return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
}

int minDepth(TreeNode* root) {
    return root ? root->left ? root->right ? min(minDepth(root->left), minDepth(root->right)) + 1
                                           : minDepth(root->left) + 1 : minDepth(root->right) + 1 : 0;
}

/// 0105, 106, 889, 1008
/// Recover binary tree from any two of pre-order, in-order, postorder traversals
/// Recover binary search tree from any of pre-order, in--order, post-order traversals

TreeNode* buildInPostHelper(const vector<int>& in, const vector<int>& post, int leftIn, int rightIn, int leftPost, int rightPost) {
    if (leftIn >= rightIn || leftPost >= rightPost) return NULL;

    TreeNode* t = new TreeNode(post[rightPost - 1]);
    for (int i = leftIn; i < rightIn; ++i) {
        if (in[i] == post[rightPost - 1]) {
            t->left = buildInPostHelper(in, post, leftIn, i, leftPost, leftPost + i - leftIn);
            t->right = buildInPostHelper(in, post, i + 1, rightIn, leftPost + i - leftIn, rightPost - 1);
            break;
        }
    }
    return t;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildInPostHelper(inorder, postorder, 0, inorder.size(), 0, postorder.size());
}

TreeNode* buildPrePostHelper(const vector<int>& pre, const vector<int>& post, int leftPre, int rightPre, int leftPost, int rightPost) {
    if (leftPre == rightPre || leftPost == rightPost) return NULL;

    TreeNode* t = new TreeNode(pre[leftPre]);

    for (int i = leftPost; i < rightPost - 1; ++i) {
        if (post[i] == pre[leftPre + 1]) {
            t->left = buildPrePostHelper(pre, post, leftPre + 1, leftPre + i + 2 - leftPost, leftPost, i + 1);
            t->right = buildPrePostHelper(pre, post, leftPre + i + 2 - leftPost, rightPre, i + 1, rightPost - 1);
            break;
        }
    }
    return t;
}

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    return buildPrePostHelper(pre, post, 0, pre.size(), 0, post.size());
}

TreeNode* bstPreHelper(const vector<int>& preorder, int left, int right) {
    if (left == right) return NULL;

    TreeNode* t = new TreeNode(preorder[left]);

    for (int i = left + 1; i < right; ++i) {
        if (preorder[i] > preorder[left]) {
            t->left = bstFromPreorderHelper(preorder, left + 1, i);
            t->right = bstFromPreorderHelper(preorder, i, right);
            return t;
        }
    }
    t->left = bstFromPreorderHelper(preorder, left + 1, right);
    return t;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    return bstFromPreorderHelper(preorder, 0, preorder.size());
}

/// 0450, 0700, 0701 search, insert, delete node from BST
TreeNode* deleteNode(TreeNode* root, const int& key) {
    if (!root) return NULL;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else if (!root->right)
        root = root->left;
    else {
        TreeNode* n = root->right;
        while(n->left)
            n = n->left;
        swap(n->val , root->val);
        root->right = deleteNode(root->right , key);
    }
    return root;
}

TreeNode* searchBST(TreeNode* root, int val) {
    return root ? val == root->val ? root : val < root->val ? searchBST(root->left, val) : searchBST(root->right, val) : NULL;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    val < root->val ? root->left = root->left ? insertIntoBST(root->left, val) : new TreeNode(val)
                    : root->right = root->right ? insertIntoBST(root->right, val) : new TreeNode(val);
    return root;
}


/// 0100 Same Tree 0101 Symmetric Tree 0110 Balanced Tree 0572 Sub-Tree 0958 Complete 0965 Uni-value

bool isSame(TreeNode* p, TreeNode* q) {
    /// Base Case 1: if both p and q are NULL, then they are the same
    /// Base Case 2: if either p or q is NULL, then they are not the same
    /// Recursion: if neither p nor q are NULL, then check
    ///     (1) if values of p and q are equal
    ///     (2) if left trees of p and q are equal
    ///     (3) if right trees of p and q are equal
    return !(p || q) ? true : !(p && q) ? false : p->val == q->val && isSame(p->left, q->left) && isSame(p->right, q->right);
}

/// 0101

bool mirror(TreeNode* p, TreeNode* q) {
    return !(p || q) ? true : !(p && q) ? false : p->val == q->val && mirror(p->left, q->right) && mirror(p->right, q->left);
}

bool isSymmetric(TreeNode* root) {
    /// Similar to isSame, except that we compare left of p with right of q and left of q with right of p
    return mirror(root, root);
}

/// 0110

int balanceHelper(TreeNode* root) {
    if (!root)
        return 0;
    int left(balanceHelper(root->left)), right(balanceHelper(root->right));
    if (left == -1 || right == -1)
        return -1;
    if (abs(left - right) > 1)
        return -1;
    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
    return balanceHelper(root) != -1;
}

/// 0958
void completeHelper(TreeNode* root, int& nodes, int index, int& maxIndex) {
    if (!root) return;
    nodes++;
    maxIndex = max(index, maxIndex);
    if (maxIndex > 100) return;
    completeHelper(root->left, nodes, index * 2, maxIndex);
    completeHelper(root->right, nodes, index * 2 + 1, maxIndex);
}

bool isCompleteTree(TreeNode* root) {
    int nodes(0), maxIndex(1);
    completeHelper(root, nodes, 1, maxIndex);
    return nodes == maxIndex;
}

/// 0965
bool isUnivalTree(TreeNode* root) {
    /// Check if all tree nodes have the same value
    /// Base case 1: if left child is not null, check if left child and parent have the same value
    /// Base case 2:
    return (!root->left || root->left->val == root->val && isUnivalTree(root->left)) &&
           (!root->right || root->right->val == root->val && isUnivalTree(root->right));
}

/// 0572
bool isSub(TreeNode* s, TreeNode* t) {
    /// Base Case 1: if s and t are the same, then they are sub-trees to each other
    /// Base Case 2: if either s or t is NULL, then t is not
    /// Recursion: if s and t are not the same, then check
    ///     (1) if left branch of s is the sub-tree of t
    ///     (2) if
    return isSame(s, t) ? true : !(s && t) ? false : isSub(s->left, t) || isSub(s->right, t);
}

/// 0102 Level Traversal (Top to Bottom) 103 Zig Zag Traversal 107 Level Traversal (Bottom to Top)
void levelHelper(TreeNode* root, int level, vector<vector<int>>& vals) {
    if (!root) return;
    vals.size() == level ? vals.push_back({root->val}) : vals[level].push_back(root->val);
    levelorderHelper(root->left, level + 1, vals);
    levelorderHelper(root->right, level + 1, vals);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> vals;
    levelOrderHelper(root, 0, vals);
    /*
    0103:
    for (int i = 0; i < vals.size(); ++i)
        if (i % 2)
            reverse(vals[i].begin(), vals[i].end())
    0107:
    reverse(vals.begin(), vals.end())
    */
    return vals;
}

/// 0108
TreeNode* arrayToTree(const vector<int>& nums, int i, int j) {
    if (i > j)
        return NULL;
    TreeNode* t = new TreeNode(nums[(i + j) / 2]);
    t->left = arrayToTree(nums, i, (i+j)/2-1);
    t->right = arrayToTree(nums, (i+j)/2+1, j);
    return t;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return arrayToTree(nums, 0, nums.size() - 1);
}

/// 0112, 0113, 0437 Path Sum
bool hasPathSum(TreeNode* root, int sum) {
    return root ? !(root->left || root->right) ? root->val == sum
                                               : hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val)
                                               : false;
}

void findPath(TreeNode* root, int sum, vector<int> path, vector<vector<int>>& paths) {
    if (!root) return;
    path.push_back(root->val);
    if (!root->left && !root->right)
        if (root->val == sum)
            paths.push_back(path);
    findPath(root->left, sum - root->val, path);
    findPath(root->right, sum - root->val, path);
}

vector<vector<int>> pathSumRootToLeaf(TreeNode* root, int sum) {
    vector<vector<int>> paths;
    findPath(root, sum, {}, paths);
    return paths;
}

void pathSumSub(TreeNode* root, const int& sum, int partSum, int& cnt) {
    if (!root) return;
    s += root->val;
    c += (s == sum);
    pathSumSub(root->left, sum, s, c);
    pathSumSub(root->right, sum, s, c);
}

int pathSumDownward(TreeNode* root, int sum) {
    if (!root) return 0;
    int c = 0;
    pathSumSub(root, sum, 0, c);
    return c + pathSum(root->left, sum) + pathSum(root->right, sum);
}

/// 0114
    TreeNode* temp = NULL;
void flatten(TreeNode* root) {
    if (!root) return;
    flatten(root->right);
    flatten(root->left);
    root->right = temp;
    root->left = NULL;
    temp = root;
}

/// 0124
int maxPathSumHelper(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    int maxLeft = max(maxPathSumHelper(root->left, maxSum), 0);
    int maxRight = max(maxPathSumHelper(root->right, maxSum), 0);
    maxSum = max(maxSum, root->val + maxLeft + maxRight);
    return max(maxLeft, maxRight) + root->val;
}
int maxPathSum(TreeNode* root) {
    int maxSum(INT_MIN);
    maxPathSumHelper(root, maxSum);
    return maxSum;
}
/// 0129

void sumRootToLeaf(TreeNode* root, int& sum, int num) {
    if (!root) return;
    num = num * 10 + root->val;
    if (!root->left && !root->right) sum += num;
    sumRootToLeaf(root->left, sum, num);
    sumRootToLeaf(root->right, sum, num);
}

int sumNumbers(TreeNode* root) {
    int sum(0);
    sumRootToLeaf(root, sum, 0);
    return sum;
}

/// 0199
void rightView(TreeNode* root, int level, vector<int>& views) {
    if (!root) return;
    if (views.size() == level)
        views.push_back({root->val});
    else
        views[level] = root->val;
    rightView(root->left, level + 1, views);
    rightView(root->right, level + 1, views); // switch left / right -> leftView
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> views;
    rightView(root, 0, views);
    return views;
}

/// 0226

TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

/// 0230
    void inorderHelperPQ(TreeNode* root, priority_queue<int>& pq, const int& k) {
        if (!root) return;
        inorderHelperPQ(root->left, pq, k);
        if (pq.size() < k)
            pq.push(root->val);
        else
            return;
        inorderHelperPQ(root->right, pq, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        inorderHelperPQ(root, pq, k);
        return pq.top();
    }

/// 0235, 0236
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return p->val >= root->val && q-> val <= root->val || p->val <= root->val && q-> val >= root->val ? root
        : root->val > p->val && root->val > q->val ? lowestCommonAncestor(root->left, p, q) : lowestCommonAncestor(root->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || p == root || q == root) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        return left && right ? root : left ? left : right;
    }

/// 0250
int countUnivalSubtrees(TreeNode* root) {
    return root ? isUnivalTree(root) + countUnivalSubtrees(root->left) + countUnivalSubtrees(root->right) : 0;
}

/// 0257
void traverseBinaryTreePaths(TreeNode* root, vector<string>& paths, string path) {
    if (!root) return;
    if (!path.empty()) path += "->";
    path += to_string(root->val);
    if (!root->left && !root->right) paths.push_back(path);
    traverseBinaryTreePaths(root->left, paths, path);
    traverseBinaryTreePaths(root->right, paths, path);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    traverseBinaryTreePaths(root, paths, "");
    return paths;
}

/// 0366
vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> leaves;
    collectLeaves(root, leaves);
    return leaves;
}

/// 0404
void addLeftLeaves(TreeNode* root, int& sum) {
    if (!root) return;

    if (root->left) {
        if (!root->left->left && !root->left->right)
            sum += root->left->val;
        else
            addLeftLeaves(root->left, sum);
    }

    addLeftLeaves(root->right, sum);
}

int sumOfLeftLeaves(TreeNode* root) {
    int sum(0);
    addLeftLeaves(root, sum);
    return sum;
}


    int collectLeaves(TreeNode* root, vector<vector<int>>& ans) {
        if (!root)
            return -1;
        int level = max(collectLeaves(root->right, ans), collectLeaves(root->left, ans)) + 1;
        level == ans.size() ? ans.push_back({root->val}) : ans[level].push_back(root->val);
        return level;
    }
    void traverseToFindMode(TreeNode* root, unordered_map<int, int>& record, int& maxCount) {
        if (!root) return;
        maxCount = max(maxCount, ++record[root->val]);
        traverseToFindMode(root->left, record, maxCount);
        traverseToFindMode(root->right, record, maxCount);
    }

    int traverseToAddNodes(TreeNode* root, unordered_map<int, int>& record, int& maxCount) {
        if (!root) return 0;
        root->val += traverseToAddNodes(root->left, record, maxCount) + traverseToAddNodes(root->right, record, maxCount);
        maxCount = max(maxCount, ++record[root->val]);
        return root->val;
    }

    int traverseToAddTilt(TreeNode* root, int& tilt) {
        if (!root) return 0;
        int left(traverseToAddTilt(root->left, tilt)), right(traverseToAddTilt(root->right, tilt));
        root->val += left + right;
        tilt += abs(left - right);
        return root->val;
    }

    void traverseToFindLargest(TreeNode* root, int level, vector<int>& largests) {
        if (!root) return;

        if (level == largests.size())
            largests.push_back(root->val);
        else
            largests[level] = max(largests[level], root->val);

        traverseToFindLargest(root->left, level + 1, largests);
        traverseToFindLargest(root->right, level + 1, largests);
    }

    int traverseToMeasure(TreeNode* root, int& d) {
        if (!root) return -1;
        int left(traverseToMeasure(root->left, d) + 1), right(traverseToMeasure(root->right, d) + 1);
        d = max(d, left + right);
        return max(left, right);
    }

    void traverseToAverage(TreeNode* root, vector<double>& vals, vector<int>& counts, int level) {
        if (!root) return;
        if (level == vals.size()) {
            vals.push_back({root->val});
            counts.push_back({1});
        } else {
            vals[level] += root->val;
            counts[level]++;
        }
        traverseToAverage(root->left, vals, counts, level + 1);
        traverseToAverage(root->right, vals, counts, level + 1);
    }

    bool findTargetHelper(TreeNode* root, const int& k, unordered_set<int>& record) {
        if (!root) return false;
        if (record.find(k - root->val) != record.end()) return true;
        record.insert(root->val);
        return findTargetHelper(root->left, k, record) || findTargetHelper(root->right, k, record);
    }

    int partHelper(TreeNode* root, unordered_set<int>& record, int& zeros) {
        if (!root) return 0;
        int val = root->val + partHelper(root->left, record, zeros) + partHelper(root->right, record, zeros);
        if (!val) zeros++;
        record.insert(val);
        return val;
    }

    void traverseToFindSecondMin(TreeNode* root, pair<int, int>& smallests) {
        if (!root) return;
        if (smallests.second == -1) {
            smallests.second = root->val;
        } else if (smallests.first == -1) {
            if (root->val < smallests.second) {
                smallests.first = smallests.second;
                smallests.second = root->val;
            } else if (root->val > smallests.second) {
                smallests.first = root->val;
            }
        } else if (root->val < smallests.second) {
            smallests.first = smallests.second;
            smallests.second = root->val;
        } else if (root->val < smallests.first && root->val > smallests.second) {
            smallests.first = root->val;
        }

        traverseToFindSecondMin(root->left, smallests);
        traverseToFindSecondMin(root->right, smallests);
    }























    /// 0501
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> record;
        vector<int> modes;
        int maxCount(0);
        traverseToFindMode(root, record, maxCount);

        for (auto it = record.begin(); it != record.end(); ++it)
            if (it->second == maxCount)
                modes.push_back(it->first);
        return modes;
    }

    /// 0508
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> record;
        vector<int> sums;
        int maxCount = 0;
        traverseToAddNodes(root, record, maxCount);

        for (auto it = record.begin(); it != record.end(); ++it)
            if (it->second == maxCount)
                sums.push_back(it->first);
        return sums;
    }

    /// 0515
    vector<int> largestValues(TreeNode* root) {
        vector<int> largests;
        traverseToFindLargest(root, 0, largests);
        return largests;
    }

    /// 0530
    int getMinimumDifference(TreeNode* root) {
        vector<int> vals(inorderTraversal(root));
        int minDiff = INT_MAX;

        for (int i = 1; i < vals.size(); ++i)
            minDiff = min(minDiff, vals[i] - vals[i-1]);

        return minDiff;
    }

    /// 0536

    /// 0606
    string tree2str(TreeNode* t) {
        return t ? !(t->left || t->right) ? to_string(t->val) : !(t->right) ? to_string(t->val) + "(" + tree2str(t->left) + ")"
                                                              : to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")" : "";
    }

    /// 0543
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter(0);
        traverseToMeasure(root, diameter);
        return diameter;
    }

    /// 0563
    int findTilt(TreeNode* root) {
        int tilt = 0;
        traverseToAddTilt(root, tilt);
        return tilt;
    }

    /// 0617
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 && t2) {
            TreeNode * root = new TreeNode(t1->val + t2->val);
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
            return root;
        } else {
            return t1 ? t1 : t2;
        }
    }

    /// 0637
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> vals;
        vector<int> counts;
        int level(0);

        traverseToAverage(root, vals, counts, level);

        for (int i = 0; i < vals.size(); ++i)
            vals[i] /= counts[i];

        return vals;
    }

/// 0653
bool findTarget(TreeNode* root, int k) {
    unordered_set<int> record;
    return findTargetHelper(root, k, record);
}

/// 0654
TreeNode* buildMBT(vector<int>& nums, int l, int r) {
    if (l == r) return NULL;

    int maxNum = nums[l];
    int index = l;

    for (int i = l + 1; i < r; ++i)
        if (maxNum < nums[i]) {
            maxNum = nums[i];
            index = i;
        }

    TreeNode* t = new TreeNode(maxNum);
    t->left = buildTree(nums, l, index);
    t->right = buildTree(nums, index+1, r);
    return t;
}


TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return buildMBT(nums, 0, nums.size());
}

/// 0687
    int uniPath(TreeNode* root, int& ans) {
        if (!root) return 0;

        int l = uniPath(root->left, ans);
        int r = uniPath(root->right, ans);
        int pl(0), pr(0);

        if (root->left)
            if (root->left->val == root->val)
                pl = l + 1;

        if (root->right)
            if (root->right->val == root->val)
                pr = r + 1;

        ans = max(ans, pl + pr);

        return max(pl, pr);
    }

    int longestUnivaluePath(TreeNode* root) {
        int longest = 0;

        uniPath(root, longest);

        return longest;
    }
/// 0998
TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    vector<int> nums = inorderTraversal(root);
    nums.push_back(val);
    return buildMBT(nums, 0, nums.size());
}
    /// 0663
    bool checkEqualTree(TreeNode* root) {
        unordered_set<int> record;
        int zeros = 0;
        int total = partHelper(root, record, zeros);
        return total ? !(total % 2) && record.find(total / 2) != record.end() : zeros > 1;
    }

    /// 0669
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root)
            return root;
        else if (root->val < L)
            return trimBST(root->right, L, R);
        else if (root->val > R)
            return trimBST(root->left, L, R);
        else {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
    }

/// 0671
int findSecondMinimumValue(TreeNode* root) {
    pair<int, int> two(-1, -1);
    traverseToFindSecondMin(root, two);
    return two.first;
}

/// 0814
TreeNode* pruneTree(TreeNode* root) {
    if (!root) return NULL;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    return !root->left && !root->right && root->val == 0 ? NULL : root;
}

/// 0872
void leafCollection(TreeNode* root, vector<int>& record) {
    if (!root) return;
    if (!root->left && !root->right)
        record.push_back(root->val);
    leafCollection(root->left, record);
    leafCollection(root->right, record);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> record1, record2;

    leafCollection(root1, record1);
    leafCollection(root2, record2);

    return record1 == record2;
}

/// 0897
TreeNode* buildIncreasingBST(const vector<int>& vals, int k) {
    if (k == vals.size()) return NULL;
    TreeNode* t = new TreeNode(vals[k]);
    t->right = buildIncreasingBST(vals, k + 1);
    return t;
}

TreeNode* increasingBST(TreeNode* root, TreeNode* tail=NULL) {
    /*
    vector<int> vals = orderTraversal(root, "in");
    return buildIncreasingBST(vals, 0);
    */
    if (!root) return tail;
    TreeNode* res = increasingBST(root->left, root);
    root->left = NULL;
    root->right = increasingBST(root->right, tail);
    return res;
}

/// 0938
int rangeSumBST(TreeNode* root, const int& L, const int& R) {
    return root ? (root->val >= L && root->val <= R ? root->val : 0) + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) : 0;
}

/// 0951
bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    return !(root1 || root2) ? true : !(root1 && root2) ? false : root1->val == root2->val
    && flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)
    || flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
}



/// 0979
int traverseCoins(TreeNode* root, int& moves) {
    if (!root) return 0;

    int l = traverseCoins(root->left, moves);
    int r = traverseCoins(root->right, moves);
    moves += abs(l) + abs(r);

    return root->val + l + r - 1;
}

int distributeCoins(TreeNode* root) {
    int moves(0);
    traverseCoins(root, moves);
    return moves;
}

/// 0988
void strFromLeaves(TreeNode* root, string str, set<string>& words) {
    if (!root) return;
    str += 'a' + root->val;
    if (!root->left && !root->right) {
        reverse(str.begin(), str.end());
        words.insert(str);
        return;
    }
    strFromLeaves(root->left, str, words);
    strFromLeaves(root->right, str, words);
}

string smallestFromLeaf(TreeNode* root) {
    set<string> words;
    strFromLeaves(root, "", words);
    return *words.begin();
}

/// 0993
void traverseToFindCousin(TreeNode* root, const int& target, int parent, int level, vector<int>& record) {
    if (!root) return;

    if (root->val == target) {
        record[0] = parent;
        record[1] = level;
        return;
    }

    traverseToFindCousin(root->left, target, root->val, level+1, record);
    traverseToFindCousin(root->right, target, root->val, level+1, record);
}

bool isCousins(TreeNode* root, int x, int y) {
    vector<int> dx(2), dy(2);
    traverseToFindCousin(root, x, 0, 0, dx);
    traverseToFindCousin(root, y, 0, 0, dy);
    return dx[0] != dy[0] && dx[1] == dy[1];
}

/// 1022
    int binaryRootToLeaf(TreeNode* root, string num) {
        if (!root)
            return stoi(num, nullptr, 2);
        num += ('0' + root->val);
        return binaryRootToLeaf(root->left, num) + binaryRootToLeaf(root->right, num);
    }

    int sumRootToLeaf(TreeNode* root) {
        return binaryRootToLeaf(root, "") / 2;
    }

/// 1026

void traverseMaxDiff(TreeNode* root, int minVal, int maxVal, int& maxDiff) {
    if (!root) {
        maxDiff = max(maxDiff, maxVal - minVal);
        return;
    }
    minVal = min(minVal, root->val);
    maxVal = max(maxVal, root->val);
    traverseMaxDiff(root->left, minVal, maxVal, maxDiff);
    traverseMaxDiff(root->right, minVal, maxVal, maxDiff);
}

int maxAncestorDiff(TreeNode* root) {
    int maxDiff(0);
    traverseMaxDiff(root, 100001, -1, maxDiff);
    return maxDiff;
}

/// 1104

    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        while (label) {
            ans.push_back(label);
            label /= 2;
        }
        reverse(ans.begin(), ans.end());
        for (int i = ans.size() - 2; i >= 0; i -= 2)
            ans[i] = 3 * (1 << i) - 1 - ans[i];
        return ans;
    }

/// 1120
pair<int, int> traverseMaxAverageSubtree(TreeNode* root, double& max_average) {
    if (!root) return {0, 0};

    int sum = root->val;
    int cnt = 1;

    pair<int, int> p1 = traverseMaxAverageSubtree(root->left, max_average);
    pair<int, int> p2 = traverseMaxAverageSubtree(root->right, max_average);

    sum += p1.first + p2.first;
    cnt += p1.second + p2.second;

    max_average = max(max_average, sum * 1.0 / cnt);

    return {sum, cnt};

}
double maximumAverageSubtree(TreeNode* root) {
    double max_average = 0.0;
    traverseMaxAverageSubtree(root, max_average);
    return max_average;
}
/// 1123

/// 0449

class CodeBST {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return root ? to_string(root->val) + " " + serialize(root->left) + serialize(root->right) : "";
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        val < root->val ? root->left = root->left ? insertIntoBST(root->left, val) : new TreeNode(val)
                        : root->right = root->right ? insertIntoBST(root->right, val) : new TreeNode(val);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i(0);

        int k(0);
        TreeNode* tn=NULL;
        while (i < data.length()) {
            //cout << i << endl;
            while (data[i] != ' ') i++;
            if (tn)
                insertIntoBST(tn, stoi(data.substr(k, i++)));
            else
                tn = new TreeNode(stoi(data.substr(k, i++)));
            k = i;
            //cout << i;
        }
        return tn;
    }
};

/// 0297
class Codec {
public:
    enum STATUS {
        ROOT_NULL = 0x0,
        ROOT = 0x1,
        LEFT = 0x2,
        RIGHT = 0x4
    };
    void s_helper(TreeNode* root, ostringstream& out) {
        char status = 0;
        if (root) status |= ROOT;
        if (root && root->left) status |= LEFT;
        if (root && root->right) status |= RIGHT;
        out.write(&status, sizeof(char));
        if (!root) return;
        out.write(reinterpret_cast<char*>(&(root->val)), sizeof(root->val));
        if (root->left) s_helper(root->left, out);
        if (root->right) s_helper(root->right, out);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        s_helper(root, out);
        return out.str();
    }

    TreeNode* helper(istringstream& in) {
        char status;
        in.read(&status, sizeof(char));
        if (!status & ROOT) return NULL;
        TreeNode* root = new TreeNode(0);
        in.read(reinterpret_cast<char*>(&(root->val)), sizeof(root->val));
        if (status & LEFT) root->left = helper(in);
        if (status & RIGHT) root->right = helper(in);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return helper(in);
    }
};
/// 0428
class CodeNary {
public:

    void serializeHelper(Node* root, wstringstream& out) {
        wchar_t status = 0;
        if (root) status++;
        if (root) status += (2 * root->children.size());
        out.write(&status, sizeof(wchar_t));
        if (!root) return;
        out.write(reinterpret_cast<wchar_t*>(&(root->val)), sizeof(root->val));
        for (int i = 0; i < root->children.size(); ++i)
            serializeHelper(root->children[i], out);
    }

    // Encodes a tree to a single string.
    wstring serialize(Node* root) {
        wstringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    Node* deserializeHelper(wstringstream& in) {
        wchar_t status;
        in.read(&status, sizeof(wchar_t));
        if (!(status % 2)) return NULL;
        Node* root = new Node();
        in.read(reinterpret_cast<wchar_t*>(&(root->val)), sizeof(root->val));
        int n = status / 2;
        root->children.resize(n);
        for (int i = 0; i < n; ++i)
            root->children[i] = deserializeHelper(in);
        return root;
    }
    // Decodes your encoded data to tree.
    Node* deserialize(wstring& data) {
        wstringstream in(ws);
        return deserializeHelper(in);
    }
};

/// 0429
void levelHelperNary(Node* root, int level, vector<vector<int>>& orders) {
    if (!root) return;
    orders.size() == level ? orders.push_back({root->val}) : orders[level].push_back(root->val);
    for (int i = 0; i < root->children.size(); ++i)
        levelHelperNary(root->children[i], level + 1, vals);
}

vector<vector<int>> levelOrderNary(Node* root) {
    vector<vector<int>> vals;
    levelHelperNary(root, 0, vals);
    return vals;
}

/// 0559
int maxDepthNary(Node* root) {
    if (!root) return 0;
    int depth = 0;
    for (int i = 0; i < root->children.size(); ++i)
        depth = max(depth, maxDepthNary(root->children[i]));
    return depth + 1;
}

/// 0589, 0590

void orderNaryHelper(Node* root, vector<int>& vals, const string& str) {
    if (!root) return;
    if (str == "pre") vals.push_back(root->val);
    for (int i = 0; i < root->children.size(); ++i)
        orderNaryHelper(root->children[i], vals, str);
    if (str == "post") vals.push_back(root->val);
}
vector<int> orderTraversalNary(Node* root, const string& str) {
    vector<int> vals;
    orderNaryHelper(root, vals, str);
    return vals;
}

