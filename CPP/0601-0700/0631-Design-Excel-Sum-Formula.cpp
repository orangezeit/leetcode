struct formula {
    unordered_map<int, int> cells;
    int val;
    formula() : val(0) {}
    formula(int v) : val(v) {}
    formula(unordered_map<int, int> c, int v) : cells(c), val(v) {}
};

class Excel {
public:
    int row, col;
    vector<vector<formula>> exc;
    stack<int> st;

    Excel(int H, char W) {
        row = H;
        col = W - 'A' + 1;
        exc = vector<vector<formula>>(row, vector<formula>(col));
    }

    int get(int r, char c) {
        return exc[r - 1][c - 'A'].val;
    }

    int calculate(int r, int c) {
        int sum(0);
        for (const auto p: exc[r][c].cells)
            sum += exc[p.first / col][p.first % col].val * p.second;
        return exc[r][c].val = sum;
    }

    void topological_sort(int r, int c) {
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (exc[i][j].cells.count(r * col + c))
                    topological_sort(i, j);
        st.push(r * col + c);
    }

    void set(int r, char c, int v) {
        exc[r - 1][c - 'A'] = formula(v);
        topological_sort(r - 1, c - 'A');
        while(!st.empty()) {
            if (!exc[st.top() / col][st.top() % col].cells.empty())
                exc[st.top() / col][st.top() % col].val = calculate(st.top() / col, st.top() % col);
            st.pop();
        }
    }

    int sum(int r, char c, vector<string> strs) {
        exc[r-1][c-'A'].cells.clear();
        for (const string& str: strs) {
            int i;
            for (i = 0; i < str.length(); ++i) {
                if (str[i] == ':') {
                    int ra(stoi(str.substr(1, i - 1))), rb(stoi(str.substr(i + 2, str.length() - i - 2)));
                    int ca(str[0] - 'A'), cb(str[i + 1] - 'A');
                    for (int j = ra; j <= rb; ++j)
                        for (int k = ca; k <= cb; ++k)
                            exc[r-1][c-'A'].cells[(j - 1) * col + k]++;
                    break;
                }
            }
            if (i == str.length())
                exc[r-1][c-'A'].cells[(stoi(str.substr(1, str.length() - 1)) - 1) * col + str[0] - 'A']++;
        }

        return calculate(r - 1, c - 'A');
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(H, W);
 * obj->set(r,c,v);
 * int param_2 = obj->get(r,c);
 * int param_3 = obj->sum(r,c,strs);
 */
