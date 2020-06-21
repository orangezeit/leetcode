struct TrieNode {
    set<int> weights;
    unordered_map<char, TrieNode*> branchs;
    TrieNode(): weights(), branchs() {}
};

class WordFilter {
public:
    TrieNode* forward = new TrieNode();
    TrieNode* backward = new TrieNode();
    void addNode(const string& word, TrieNode* tn, const int& i) {
        TrieNode* temp = tn;
        for (const char& letter: word) {
            if (!temp->branchs.count(letter))
                temp->branchs[letter] = new TrieNode();
            temp = temp->branchs[letter];
            temp->weights.insert(i);
        }
    }
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            addNode(words[i], forward, i);
            reverse(words[i].begin(), words[i].end());
            addNode(words[i], backward, i);
        }
    }
    int helper(const set<int>& s1, const set<int>& s2) {
        if (s1.empty() && s2.empty()) return 0;
        if (s1.empty()) return *(--s2.end());
        if (s2.empty()) return *(--s1.end());

        auto it1 = --s1.end();
        auto it2 = --s2.end();

        while (it1 != s1.begin() && it2 != s2.begin()) {
            if (*it1 == *it2) return *it1;
            *it1 > *it2 ? --it1 : --it2;
        }

        if (it1 == s1.begin()) {
            while (it2 != s2.begin()) {
                if (*it1 == *it2) return *it1;
                --it2;
            }
        }
        if (it2 == s2.begin()) {
            while (it1 != s1.begin()) {
                if (*it1 == *it2) return *it1;
                --it1;
            }
        }
        return *it1 == *it2 ? *it1 : -1;
    }
    int f(string prefix, string suffix) {
        TrieNode* temp1 = forward;
        for (const char& c: prefix) {
            if (!temp1->branchs.count(c)) return -1;
            temp1 = temp1->branchs[c];
        }

        reverse(suffix.begin(), suffix.end());

        TrieNode* temp2 = backward;
        for (const char& c: suffix) {
            if (!temp2->branchs.count(c)) return -1;
            temp2 = temp2->branchs[c];
        }

        return helper(temp1->weights, temp2->weights);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
