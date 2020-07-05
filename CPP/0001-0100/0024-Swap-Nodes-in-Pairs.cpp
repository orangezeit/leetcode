class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* pre = dummyHead;
        ListNode* n1 = NULL;
        ListNode* n2 = NULL;
        ListNode* post = NULL;

        while (pre->next) {
            n1 = pre->next;

            if (n1->next) {
                n2 = n1->next;
                post = n2->next;
            } else {
                break;
            }

            pre->next = n2;
            n2->next = n1;
            n1->next = post;
            pre = n1;
        }

        head = dummyHead->next;
        delete dummyHead, pre, n1, n2, post;
        return head;
    }
};
