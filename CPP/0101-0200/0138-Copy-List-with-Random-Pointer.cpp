/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> record;
        Node* temp = head;
        record[nullptr] = nullptr;
        while (temp) {
            record[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp) {
            record[temp]->next = record[temp->next];
            record[temp]->random = record[temp->random];
            temp = temp->next;
        }
        return record[head];
    }
};
