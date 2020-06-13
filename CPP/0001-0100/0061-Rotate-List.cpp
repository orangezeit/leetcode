    int countNode(ListNode* head) {
        int n = 0;
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        
        while (temp->next) {
            temp = temp->next;
            n++;
        }
        
        delete dummyHead, temp;
        return n;
    }
    
    ListNode* rotate(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        
        while (n) {
            temp = temp->next;
            n--;
        }
        
        ListNode* newHead = temp->next;
        ListNode* newTemp = newHead;
        
        while (newTemp->next) {
            newTemp = newTemp->next;
        }
        
        temp->next = newTemp->next;
        newTemp->next = head;
        head = newHead;
        
        delete dummyHead, temp, newHead, newTemp;
        return head;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int n = countNode(head);
        
        if (n == 0) {
            return head;
        } else if (k % n == 0) {
            return head;
        } else {
            return rotate(head, n - k % n);
        }
    }
