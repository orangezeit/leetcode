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
    int maxNum(ListNode* head) {
        ListNode* temp = head;
        int maxNum = head->val;

        while (temp->next != NULL) {
            temp = temp->next;
            if (temp->val > maxNum) {
                maxNum = temp->val;
            }
        }

        return maxNum;
    }

    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) {
            return head;
        }

        if (x > maxNum(head)) {
            //return head;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* inserted;
        if (temp->val < x) {
            prev = head;
        }
        //cout << print(head) << endl;

        while (temp->next != NULL) {

            while (temp->next->val >= x) {
                temp = temp->next;
                if (temp->next == NULL) {
                    return head;
                }
            }

            if (prev == NULL) {
                //cout << "a";
                inserted = new ListNode(temp->next->val);
                inserted->next = head;
                temp->next = temp->next->next;
                head = inserted;
                prev= head;
                //return head;
            } else {
                inserted = new ListNode(temp->next->val);
                inserted->next = prev->next;
                prev->next = inserted;
                temp->next = temp->next->next;
                prev = prev->next;
                temp = prev;
            }

        }



        return head;
    }

};
