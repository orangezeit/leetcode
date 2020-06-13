/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        while (temp->next) {
            int x(m), y(n);
            while (temp->next && x) {
                temp = temp->next;
                x--;
            }
            ListNode* temp2 = temp->next;
            while (temp2 && y) {
                //ListNode* temp3 = temp2;
                temp2 = temp2->next;
                //delete temp3;
                y--;
            }
            temp->next = temp2;
        }
        //delete dummy, temp;
        return head;
    }
};
