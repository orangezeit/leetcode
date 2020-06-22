/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> s;
        Node* temp = head;
        while (temp) {
            if (temp->child) {
                if (temp->next) s.push(temp->next);
                temp->next = temp->child;
                temp->next->prev = temp;
                temp->child = NULL;
            } else if (!(temp->next || s.empty())) {
                temp->next = s.top();
                temp->next->prev = temp;
                s.pop();
            }
            temp = temp->next;
        }


        return head;
    }
};
