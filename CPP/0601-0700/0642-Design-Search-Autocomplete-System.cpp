struct TrieNode {
    int cnt;
    unordered_map<char, TrieNode*> branchs;
    TrieNode(): cnt(0), branchs() {}
};

struct pairCompare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b){
        return a.first == b.first ? a.second < b.second : a.first > b.first;
    }
};

using pqp = priority_queue<pair<int, string>, vector<pair<int, string>>, pairCompare>;

class AutocompleteSystem {
private:
    string str;
    TrieNode* history = new TrieNode();
    TrieNode* search = history;
    bool marked = false;

    void addTrieNode(const string& s) {
        TrieNode* temp = history;
        for (const char& letter: s) {
            if (!temp->branchs.count(letter))
                temp->branchs[letter] = new TrieNode();
            temp = temp->branchs[letter];
        }
        temp->cnt++;
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {

        int k(0);

        for (const string& sentence: sentences) {
            TrieNode* temp = history;
            for (const char& letter: sentence) {
                if (!temp->branchs.count(letter))
                    temp->branchs[letter] = new TrieNode();
                temp = temp->branchs[letter];
            }
            temp->cnt = times[k++];
        }
    }

    void traverseTrie(pqp& pq, TrieNode* temp, string& s) {
        if (temp->cnt) {
            pq.push({temp->cnt, s});
            if (pq.size() > 3) pq.pop();
        }

        for (const auto& p: temp->branchs) {
            if (p.second) {
                s += p.first;
                traverseTrie(pq, p.second, s);
                s.pop_back();
            }
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            addTrieNode(str);
            str.clear();
            search = history;
            marked = false;
            return {};
        } else {
            str += c;
            if (marked) return {};
            if (search->branchs.count(c)) {
                search = search->branchs[c];
                pqp pq;
                traverseTrie(pq, search, str);
                vector<string> ans(pq.size());
                int k = pq.size() - 1;
                while (!pq.empty()) {
                    ans[k--] = pq.top().second;
                    pq.pop();
                }
                return ans;
            } else {
                marked = true;
                return {};
            }
        }
        return {};
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
