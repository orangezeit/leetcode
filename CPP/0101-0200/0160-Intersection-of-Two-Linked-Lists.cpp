class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        if (!p1 || !p2) return nullptr;
        while (p1 && p2 && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2) return p1;
            if (!p1) p1 = headB;
            if (!p2) p2 = headA;
        }
        return p1;
    }
};
