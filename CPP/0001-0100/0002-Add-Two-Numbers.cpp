class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // N = max length of two lists
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        ListNode* num = new ListNode(0);
        ListNode* head = num;

        while (l1 || l2) {
            if (l1) {
                head->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                head->val += l2->val;
                l2 = l2->next;
            }
            if (head->val >= 10) {
                head->next = new ListNode(1);
                head->val %= 10;
            } else if (l1 || l2)
                head->next = new ListNode(0);
            head = head->next;
        }

        return num;
    }
};
