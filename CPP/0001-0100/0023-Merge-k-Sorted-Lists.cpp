/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct compare {
    bool operator()(ListNode* a, ListNode* b) const {
        return a->val > b->val;
    }
};
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Time Complexity: O(N lg K)
        // Space Complexity: O(K)
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (ListNode* list: lists)
            if(list) pq.push(list);
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            temp->next = node;
            temp = temp->next;
            if (node->next) pq.push(node->next);
        }
        temp = ans->next;
        delete ans;
        return temp;
    }
};
