class Solution {
public:
    int diameter(Node* root) {
        int ans(0);
        function<int(Node*)> dfs = [&](Node* r) {
            if (!r) return 0;
            int first(0), second(0); // largest and second largest
            for (const auto& nxt: r->children) {
                int d = dfs(nxt) + 1;
                if (d > first) {
                    second = first;
                    first = d;
                } else if (d > second)
                    second = d;
            }
            ans = max(ans, first + second);
            return first;
        };
        dfs(root);
        return ans;
    }
};
