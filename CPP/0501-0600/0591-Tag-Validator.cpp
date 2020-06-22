class Solution {
public:
    bool isValid(string code) {
        const string CONTENT("[CDATA[");
        string tag;
        stack<string> tags;
        // j: index of cdata CONTENT
        // k: counter of unbalanced < so far
        // a: counter of ! inside tag
        // b: counter of / inside tag
        int j(0), k(0), a(0), b(0);
        // whether head or tail tag, whether inside the tag, whether inside the cdata
        bool head(true), inside(false), cdata(false);

        for (int i = 0; i < code.length(); i++) {
            // outside a valid closed tag
            if (i && !inside && tags.empty()) return false;

            if (cdata) {
                // doesn't match
                if (j < 7 && CONTENT[j++] != code[i])
                    return false;
                // not enough chars to close cdata
                if (i + 3 > code.length())
                    return false;
                if (code[i] == ']' && code.substr(i, 3) == "]]>") {
                    // close cdata and reset to default
                    k--;
                    cdata = false;
                    a = j = 0;
                    i += 2;
                }
                // skip cdata_content
            } else if (code[i] == '<') {
                // increase # of unbalanced <
                k++;
                inside = true;
            } else if (code[i] == '>') {
                // decrease # of unbalanced <, keep in mind that unbalanced < is ok
                if (k) k--;
                if (inside) {
                    if (head) {
                        if (tag.empty()) return false;
                        tags.push(tag);
                    } else {
                        if (tags.empty() || tags.top() != tag) return false;
                        tags.pop();
                    }
                    // reset to default
                    tag.clear();
                    head = true;
                    inside = false;
                    b = 0;
                }
            } else if (inside) {
                if (code[i] == '!') {
                    // at most one ! right after < -> indicates cdata
                    if (a++ || code[i - 1] != '<') return false;
                    inside = false;
                    cdata = true;
                } else if (code[i] == '/') {
                    // at most one / right after < -> indicates closed tag
                    if (b++ || code[i - 1] != '<') return false;
                    head = false;
                } else if (code[i] >= 'A' && code[i] <= 'Z') {
                    tag += code[i];
                    if (tag.length() > 9) return false;
                } else {
                    return false;
                }
            }
        }
        // check (if cdata is finished) and (if tags are all closed) and (if < are all balanced)
        return !cdata && tags.empty() && !k;
    }
};
