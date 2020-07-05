class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int cnt(0), depth(0);

        for (const char& c: seq)
            c == '(' ? depth = max(depth, ++cnt + 1) : cnt--;

        vector<int> ans(seq.length());

        for (int i = 0; i < seq.length(); ++i)
            ans[i] = seq[i] == '(' ? ++cnt > depth / 2 : cnt-- > depth / 2;

        return ans;

    }
};
