class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        ListNode *curr = head, *prev = nullptr;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};
