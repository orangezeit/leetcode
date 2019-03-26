    int countNode(ListNode* n) {
        if (n == NULL) {
            return 0;
        }
        
        int num = 1;
        
        while (n->next != NULL) {
            num++;
            n = n->next;
        }
        
        return num;
    }
    
    ListNode* editNode(ListNode* large, ListNode* small) {
        ListNode* temp = large;

        while(small != NULL) {
            temp->val += small->val;
            
            if (temp->val < 10) {
                temp = temp->next;
            } else {
                temp->val %= 10;
                temp = temp->next;
                temp->val++;
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
                    temp->val++;
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
