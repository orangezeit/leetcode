class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf && quadTree2->isLeaf) {

            return new Node(quadTree1->val || quadTree2->val, true);
        } else if (quadTree1->isLeaf) {
            return quadTree1->val ? new Node(true, true) : quadTree2;
        } else if (quadTree2->isLeaf) {
            return quadTree2->val ? new Node(true, true) : quadTree1;
        } else {
            Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
            Node* tr = intersect(quadTree1->topRight, quadTree2->topRight);
            Node* bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            Node* br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tl->val == tr->val && tr->val == bl->val && bl->val == br->val)
                return new Node(tl->val, true);
            return new Node(true, false, tl, tr, bl, br);
        }
    }
};
