class RecentCounter {
private:
    ListNode* n = new ListNode(0);
    ListNode* head = n;
    //vector<int> record;
    int i = 0;
    int k = 0;
public:
    RecentCounter() {
        //record.resize(10000);
    }

    int ping(int t) {


        n->next = new ListNode(t);
        n = n->next;

        if (head->val == 0) {
            head = head->next;
        }

        k++;
        while (t-3000 > head->val) {
            head = head->next;
            i++;
        }

        return k - i;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
