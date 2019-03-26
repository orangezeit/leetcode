    TreeNode* buildTree(ListNode* head, int i, int j) {
        
        if (i == j) {
            return new TreeNode(head->val);
        }
        
        ListNode* temp = head;
        
        int k = (i+j+1)/2;
        
        while (k > i) {
            temp = temp->next;
            k--;
        }
        
        TreeNode* n = new TreeNode(temp->val);
        
        n->left = buildTree(head, i, (i+j+1)/2-1);
        
        if ((i+j+1)/2+1 <= j) {
            n->right = buildTree(temp->next, (i+j+1)/2+1, j);
        }

        return n;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        int len = 1;
        
        ListNode* temp = head;
        
        while(temp->next != NULL) {
            len++;
            temp = temp->next;
        }
        
        return buildTree(head, 0, len-1);
    }
