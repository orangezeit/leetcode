class StockSpanner {
private:
    stack<pair<int, int>> s;
    int level;
public:
    StockSpanner() {
        level = 0;
    }

    int next(int price) {
        pair<int, int> p = {price, ++level};

        if (!s.empty())
            while (s.top().first <= price) {
                s.pop();
                if (s.empty())
                    break;
            }

        int n = s.empty() ? level : level - s.top().second;
        s.push(p);
        return n;
    }
};
