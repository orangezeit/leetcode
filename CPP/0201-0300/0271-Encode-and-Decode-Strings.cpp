class Codec {
public:
    vector<pair<int, int>> splits;
    //string str;
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int k = 0;
        string str;
        splits.resize(strs.size());
        for (int i = 0; i < strs.size(); ++i) {
            splits[i] = {k, strs[i].length()};
            str += strs[i];
            k += strs[i].length();
        }
        return str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res(splits.size());

        for (int i = 0; i < splits.size(); ++i) {
            res[i] = s.substr(splits[i].first, splits[i].second);
        }
        splits.clear();
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
