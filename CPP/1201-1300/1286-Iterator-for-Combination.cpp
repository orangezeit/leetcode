class CombinationIterator {
public:
    vector<int> indices;
    string str;
    bool hn;
    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        indices.resize(combinationLength);
        for (int i = 0; i < combinationLength; ++i) {
            indices[i] = i;
        }
        hn = true;
        //cout << combinationLength << endl;
    }

    string next() {
        string ans;
        for (int i: indices) ans += str[i];
        //cout << ans << endl;
        int k = indices.size() - 1;
        int i = 1;
        while (indices[k] == str.length() - i) {
            k--;
            i++;
            if (k == -1) {
                hn = false;
                break;
            }
        }
        if (hn) {
            indices[k]++;
            for (int n = k + 1; n < indices.size(); ++n) {
                indices[n] = indices[n - 1] + 1;
            }
        }
        return ans;
    }

    bool hasNext() {
        return hn;
    }
};
