class BrowserHistory {
public:
    stack<string> pages, pages2;
    BrowserHistory(string homepage) {
        pages.push(homepage);
    }

    void visit(string url) {
        while (!pages2.empty()) pages2.pop();
        pages.push(url);
    }

    string back(int steps) {
        for (int i = 0; i < steps; ++i) {
            if (pages.size() == 1) break;
            pages2.push(pages.top());
            pages.pop();
        }
        return pages.top();
    }

    string forward(int steps) {
        for (int i = 0; i < steps; ++i) {
            if (pages2.empty()) break;
            pages.push(pages2.top());
            pages2.pop();
        }
        return pages.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
