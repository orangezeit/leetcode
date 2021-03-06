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
    //queue<ListNode*> q;
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> st;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* temp = dummy;
        ListNode* prev = dummy;
        
        while (temp) {
            temp = temp->next;
            st.push(temp);
            while (st.size() == k) {
                if (!temp) break;
                ListNode* next = temp->next;
                while (st.size()) {
                    prev->next = st.top();
                    prev = prev->next;
                    st.pop();
                }
                prev->next = next;
                temp = prev;
            }
        }
        
        return dummy->next;
    }
};
