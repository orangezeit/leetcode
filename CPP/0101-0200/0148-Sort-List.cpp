/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // merge sort, top down
    pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) swap(l1, l2);
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
        if (l1) temp->next = l1;
        if (l2) temp->next = l2;
        while (temp->next) temp = temp->next;
        return {dummy->next, temp};
    }

    ListNode* split(ListNode* head, int n) {
        while (--n && head) head = head->next;
        ListNode* rest = head ? head->next : nullptr;
        if (head) head->next = nullptr;
        return rest;
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int len(1);
        ListNode* curr = head;
        while (curr = curr->next) ++len;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* l;
        ListNode* r;
        ListNode* tail;

        for (int n = 1; n < len; n <<= 1) {
            curr = dummy->next;
            tail = dummy;
            while (curr) {
                l = curr;
                r = split(l, n);
                curr = split(r, n);
                auto m = merge(l, r);
                tail->next = m.first;
                tail = m.second;
            }
        }
        return dummy->next;
    }
};
