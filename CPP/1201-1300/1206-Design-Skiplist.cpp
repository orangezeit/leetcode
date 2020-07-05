struct Node {
    int val;
    int count;
    Node* next;
    Node* down;
    Node(int v, int c, Node* nt, Node* dn) : val(v), count(c), next(nt), down(dn) {}
};

class Skiplist {
private:
    stack<Node*> insertNodes;
    Node* head;
public:
    Skiplist() {
        head = new Node(-1, 0, nullptr, nullptr);
    }

    void print() {
        Node* t = head;
        while (t) {
            Node* x = t;
            while (x) {
                cout << '(' << x->val << ',' << x->count << ')' << ' ';
                x = x->next;
            }
            cout << '\n';
            t = t->down;
        }
    }

    bool search(int target) {
        Node* temp = head;
        while (temp) {
            while(temp->next && temp->next->val < target)
                temp = temp->next;
            if (temp->next && temp->next->val == target) return true;
            temp = temp->down;
        }
        return false;
    }

    void add(int num) {
        while (!insertNodes.empty()) insertNodes.pop();

        Node* temp = head;
        while (temp) {
            while(temp->next && temp->next->val < num)
                temp = temp->next;
            if (temp->next && temp->next->val == num) {
                temp = temp->next;
                while (temp) {
                    temp->count++;
                    temp = temp->down;
                }
                return;
            }
            insertNodes.push(temp);
            temp = temp->down;
        }

        Node* dn = nullptr;
        int upwards(1);

        while (!insertNodes.empty() && upwards) {
            insertNodes.top()->next = new Node(num, 1, insertNodes.top()->next, dn);
            dn = insertNodes.top()->next;
            insertNodes.pop();
            upwards = rand() & 1;
        }

        if (upwards) head = new Node(-1, 0, new Node(num, 1, nullptr, dn), head);
    }

    bool erase(int num) {
        Node* temp = head;
        bool found(false);
        while (temp) {
            while(temp->next && temp->next->val < num)
                temp = temp->next;
            if (temp->next && temp->next->val == num) {
                found = true;
                if (!(--temp->next->count)) {
                    Node* x = temp->next;
                    temp->next = temp->next->next;
                    delete x;

                }
            }
            temp = temp->down;
        }
        return found;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
