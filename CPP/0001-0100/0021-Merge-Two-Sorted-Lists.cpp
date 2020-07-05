class Solution {
public:
    ListNode* addNode(ListNode* n, int val) {
        if (n == nullptr) {
            n = new ListNode(val);
        } else {
            ListNode* temp = n;
            while (temp->next) temp = temp->next;
            temp->next = new ListNode(val);
            delete temp;
        }

        return n;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Time Complexity: O(L1 + L2)
        // Space Complexity: O(L1 + L2)
        ListNode* merged = nullptr;

        while (l1 || l2) {
            if (l1 && l2) {
                if (l1->val <= l2->val) {
                    merged = addNode(merged, l1->val);
                    l1 = l1->next;
                } else {
                    merged = addNode(merged, l2->val);
                    l2 = l2->next;
                }
            } else if (l1) {
                merged = addNode(merged, l1->val);
                l1 = l1->next;
            } else {
                merged = addNode(merged, l2->val);
                l2 = l2->next;
            }
        }

        return merged;
    }
};
