class Solution {
private:
    vector<char> mapping;
public:
    char find(char c) {
        if (c != mapping[c - 'a'])
            return find(mapping[c - 'a']);
        return c;
    }

    void unite(char c1, char c2) {
        char p1 = find(c1);
        char p2 = find(c2);

        mapping[p1 - 'a'] = p2;
    }

    void update() {
        for (int i = 0; i < 26; ++i) {
            mapping[i] = find('a' + i);
        }
    }

    char find_first(char c) {
        char p = mapping[c - 'a'];

        for (int i = 0; i < 26; ++i)
            if (mapping[i] == p)
                return 'a' + i;
        return '0';
    }

    string smallestEquivalentString(string A, string B, string S) {
        mapping.resize(26);

        for (int i = 0; i < 26; ++i) {
            mapping[i] = 'a' + i;
        }

        for (int i = 0; i < A.length(); ++i) {
            unite(A[i], B[i]);
        }
        update();
        //for (int i = 0; i < 26; ++i) cout << mapping[i] << " ";
        for (int i = 0; i < S.length(); ++i) {
            S[i] = find_first(S[i]);
        }
        return S;
    }
};
