class Solution {
public:
    array<int, 26> getKey(const string& str) {
        array<int, 26> arr = {};
        for(auto&& c: str) arr[move(c) - 'a']++;
        return arr;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> m;
        for(auto&& str : strs)
            m[getKey(str)].push_back(move(str));

        vector<vector<string>> ans;
        transform(m.begin(), m.end(),
                  back_inserter(ans), [](auto&& p){ return get<vector<string>>(move(p)); });
        return ans;
    }
};
