class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        ListNode *dummy = new ListNode(0, head), *c = dummy;
        for (int i = 0; i < m - 1; i++) dummy = dummy->next;

        ListNode *curr = dummy->next;

        for (int i = 0; i < n - m; i++) {
            ListNode* temp = dummy -> next;
            dummy->next = curr->next;
            curr->next=curr->next->next;
            dummy->next->next=temp;
        }

        return c->next;
    }
};
