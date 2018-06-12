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
    int countNode(ListNode* n) {
        int num = 1;
        while (n->next != NULL) {
            ++num;
            n = n->next;
        }
        return num;
    }
    
    ListNode* editNode(ListNode* large, ListNode* small) {
        ListNode* temp = large;

        while(small != NULL) {
            temp->val = temp->val + small->val;
            
            if (temp->val < 10) {
                temp = temp->next;
            } else {
                temp->val = temp-> val % 10;
                    
                if (temp->next != NULL) {
                    temp = temp->next;
                    temp->val = temp->val + 1;
                } else {
                    temp->next = new ListNode(1);
                }
            }
            small = small->next;
        }
        
        while (temp != NULL) {
            if (temp->val < 10) {
                    temp = temp->next;
            } else {
                temp->val = 0;
                
                if (temp->next != NULL) {
                    temp = temp->next;
                    temp->val = temp->val + 1;
                } else {
                    temp->next = new ListNode(1);
                }
            }
        }
        
        return large;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (countNode(l1) > countNode(l2)) {
            return editNode(l1, l2);
        } else {
            return editNode(l2, l1);
        }

    }
};
