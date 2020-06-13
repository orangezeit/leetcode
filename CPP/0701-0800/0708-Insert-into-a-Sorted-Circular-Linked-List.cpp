/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal, NULL);
            head->next = head;
            return head;
        } else {
            Node* given = head;
            do {
                if (head->val <= head->next->val) {
                    if (head->val <= insertVal && insertVal <= head->next->val) {
                        Node* temp = head->next;
                        head->next = new Node(insertVal, head->next);
                        while (head != given) head = head->next;
                        return head;
                    }
                } else {
                    if (insertVal >= head->val || insertVal <= head->next->val) {
                        head->next = new Node(insertVal, head->next);
                        while (head != given) head = head->next;
                        return head;
                    }
                }
                head = head->next;
            } while (head != given);
            head->next = new Node(insertVal, head->next);
            return head;
        }
    }
};
