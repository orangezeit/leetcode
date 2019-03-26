    int measure(ListNode* root) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = root;
        
        int n = 0;
        
        while (dummyHead->next) {
            dummyHead = dummyHead->next;
            n++;
        }
        
        return n;
    }
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k);
        int n = measure(root);
        int i = 0;
        int a = n / k;
        int b = n % k;
        
        ListNode* remain = root;
        
        while (remain) {
            ListNode* dummyHead = new ListNode(0);
            dummyHead->next = remain;
            ListNode* part = dummyHead;
            
            int c = a + (b-- > 0 ? 1 : 0);
            while (c--) dummyHead = dummyHead->next;
            
            ListNode* temp = dummyHead->next;
            dummyHead->next = NULL;
            parts[i++] = part->next;
            remain = temp;
        }
        
        return parts;
    }
