class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* start = dummyHead;
        ListNode* end = dummyHead;

        while (n--) end = end->next;

        while (end->next) {
            start = start->next;
            end = end->next;
        }

        ListNode* temp = start->next;
        start->next = start->next->next;
        head = dummyHead->next;
        delete dummyHead, start, end, temp;

        return head;
    }
};
