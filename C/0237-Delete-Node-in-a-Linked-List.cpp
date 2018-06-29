    void deleteNode(ListNode* node) {
        node->val = node->next->val;   // remove next val to current val
        node->next = node->next->next; // remove next node
    }
