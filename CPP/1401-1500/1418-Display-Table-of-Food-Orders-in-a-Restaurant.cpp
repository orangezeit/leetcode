class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {

        map<int, map<string, int>> table;
        set<string> items;

        for (const vector<string>& order: orders) {
            string n(order[1]), food(order[2]);
            table[stoi(n)][food]++;
            items.insert(food);
        }

        int m(table.size()), n(items.size());

        vector<vector<string>> ans(m + 1, vector<string>(n + 1, "0"));
        ans[0][0] = "Table";
        int i(1);

        for (const string& item: items)
            ans[0][i++] = item;

        i = 1;

        for (const auto&[num, combo]: table) {
            int j(1);
            for (const auto&[food, cnt]: combo) {
                while (ans[0][j] != food) j++;
                ans[i][j++] = to_string(cnt);
            }
            ans[i++][0] = to_string(num);
        }

        return ans;
    }
};
