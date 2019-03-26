    bool hasCycle(ListNode *head) {
        ListNode* p = new ListNode(0);
        
        ListNode* temp;

        if (head == NULL || head->next == NULL) {
            return false;
        }
        
        while (head != NULL) {
            if (head == head->next) {
                return true;
            }
            
            temp = head->next;
            head->next = p;
            head = temp;
            
            if (head->next == NULL) {
                return false;
            } else if (head->next->next == NULL) {
                return false;
            } else if (head->next->next == p) {
                return true;
            }
            
        }
        
        return false;
        
    }
