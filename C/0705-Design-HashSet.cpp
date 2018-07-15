private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    vector<ListNode*> hash;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        hash.resize(100);
        
        for (int i = 0; i < 100; ++i) {
            hash[i] = new ListNode(0);
        }
    }
    
    void add(int key) {
        ListNode* temp = hash[key % 100];
        
        while (temp->next != NULL) {
            temp = temp->next;
            if (temp->val == key) {
                return;
            }
        }
        temp->next = new ListNode(key);
    }
    
    void remove(int key) {
        ListNode* temp = hash[key % 100];
        
        while (temp->next != NULL) {
            if (temp->next->val == key) {
                temp->next = temp->next->next;
                return;
            }
            temp = temp->next;
        }
    }
    
    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) {
        ListNode* temp = hash[key % 100];
        
        while (temp->next != NULL) {
            temp = temp->next;
            if (temp->val == key) {
                return true;
            }
        }
        
        return false;
    }
