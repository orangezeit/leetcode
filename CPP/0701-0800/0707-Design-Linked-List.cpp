class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(NULL) {}
    };

    ListNode* head;     // linked list
    int n;              // index of last node
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        n = -1;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index > n || index < 0) {
            return -1;
        } else {
            ListNode* temp = head;

            while (index--) {
                temp = temp->next;
            }

            return temp->val;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newHead = new ListNode(val);
        newHead->next = head;
        head = newHead;

        n++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (head == NULL) {
            head = new ListNode(val);
        } else {
            ListNode* temp = head;

            while (temp->next) {
                temp = temp->next;
            }

            temp->next = new ListNode(val);
        }

        n++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == 0) {
            ListNode* newHead = new ListNode(val);
            newHead->next = head;
            head = newHead;
            n++;
        } else if (index > 0 && index <= n + 1) {
            index--;
            ListNode* temp = head;

            while (index--) {
                temp = temp->next;
            }

            ListNode* post = temp->next;
            temp->next = new ListNode(val);
            temp->next->next = post;
            n++;
        }

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index == 0) {
            head = head->next;
            n--;
        } else if (index > 0 && index <= n) {
            index--;
            ListNode* temp = head;

            while (index--) {
                temp = temp->next;
            }

            temp->next = temp->next->next;
            n--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
