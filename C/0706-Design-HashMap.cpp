private:
    struct ListNode {
        int key;
        int value;
        ListNode* next;
        ListNode(int x, int y) : key(x), value(y), next(NULL) {}
    };
    
    vector<ListNode*> hash;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        hash.resize(100);
        
        for (int i = 0; i < 100; ++i) {
            hash[i] = new ListNode(0, 0);
        }
    }
    
    /** value will always be positive. */
    void put(int key, int value) {
        ListNode* temp = hash[key % 100];
        
        while (temp->next != NULL) {
            temp = temp->next;
            if (temp->key == key) {
                temp->value = value;
                return;
            }
        }
        temp->next = new ListNode(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        ListNode* temp = hash[key % 100];
        
        while (temp->next != NULL) {
            temp = temp->next;
            if (temp->key == key) {
                return temp->value;
            }
            
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        ListNode* temp = hash[key % 100];
        
        while (temp->next != NULL) {
            if (temp->next->key == key) {
                temp->next = temp->next->next;
                return;
            }
            temp = temp->next;
        }
    }
