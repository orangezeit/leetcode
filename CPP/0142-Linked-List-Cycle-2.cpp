    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        
        unordered_set<ListNode*> nodes;
        ListNode* temp = head;
        
        while (nodes.find(temp) == nodes.end()) {
            nodes.insert(temp);
            temp = temp->next;
            if (temp == NULL) {
                return NULL;
            }
        }
        
        return temp;
    }
