class StringIterator {
public:
    queue<pair<char, int>> q;

    StringIterator(string compressedString) {
        compressedString += ' ';
        char c;
        string num;

        for (int i = 0; i < compressedString.length(); ++i) {
            if (compressedString[i] >= '0' && compressedString[i] <= '9') {
                num += compressedString[i];
            } else {
                if (!num.empty()) {
                    q.push({c, stoi(num)});
                    num.clear();
                }
                c = compressedString[i];
            }
        }
    }

    char next() {
        if (q.empty()) return ' ';
        char c = q.front().first;
        if (--q.front().second == 0) q.pop();
        return c;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
