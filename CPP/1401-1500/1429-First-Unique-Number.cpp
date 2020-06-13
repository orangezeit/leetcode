class FirstUnique {
public:
    queue<int> q;
    unordered_set<int> s1, s2;
    FirstUnique(vector<int>& nums) {
        for (const int& i: nums) {
            if (s2.count(i)) continue;
            if (s1.count(i)) {
                s1.erase(i);
                s2.insert(i);
            } else {
                s1.insert(i);
                q.push(i);
            }
        }
    }

    int showFirstUnique() {
        while (!q.empty() && s2.count(q.front())) q.pop();
        return q.empty() ? -1 : q.front();
    }

    void add(int value) {
        if (s2.count(value)) return;
        if (s1.count(value)) {
            s1.erase(value);
            s2.insert(value);
        } else {
            s1.insert(value);
            q.push(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
