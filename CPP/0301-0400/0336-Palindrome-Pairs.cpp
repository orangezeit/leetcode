struct TrieNode {
    int index;
    unordered_map<char, TrieNode*> branchs;
    TrieNode(): index(-1), branchs() {}
};

class Solution {
public:
    TrieNode* backward = new TrieNode();

    void addNode(string word, TrieNode* tn, const int& i) {
        reverse(word.begin(), word.end());
        TrieNode* temp = tn;
        for (const char& letter: word) {
            if (!temp->branchs.count(letter))
                temp->branchs[letter] = new TrieNode();
            temp = temp->branchs[letter];
        }
        temp->index = i;
    }
    bool isPalindrome(const string& str, int i) {
        for (int k = 0; k < (str.length() - i) / 2; ++k) {
            if (str[i + k] != str[str.length() - 1 - k])
                return false;
        }
        return true;
    }
    void traverse(TrieNode* tn, unordered_set<int>& others, string& str) {
        if (tn->index != -1 && isPalindrome(str, 0)) others.insert(tn->index);
        //cout << "t" << tn->branchs.size() << endl;
        for (const auto& p: tn->branchs) {
            str += p.first;
            traverse(p.second, others, str);
            str.pop_back();
        }
        //cout << "is" << isPalindrome(str, 0) << endl;

    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            addNode(words[i], backward, i);
        }

        vector<vector<int>> ans;
        int k(0);
        for (const string& word: words) {
            TrieNode* temp = backward;
            for (int i = 0; i <= word.length(); ++i) {
                //cout << word[i];
                if (i == word.length()) {

                    TrieNode* temp2 = temp;
                    unordered_set<int> others;
                    string s;
                    traverse(temp2, others, s);
                    //cout << temp->index << endl;
                    for (const auto& i: others)
                        if (k != i)
                            ans.push_back({k, i});
                    break;
                }
                if (temp->index != -1) {
                    //cout << temp->index << endl;
                    // verify if the remaining part is palindrome
                    if (isPalindrome(word, i) && k != temp->index) ans.push_back({k, temp->index});

                }
                if (temp->branchs.count(word[i])) {
                    temp = temp->branchs[word[i]];
                } else {
                    break;
                }

            }//cout << endl;
            k++;
        }

        return ans;
    }
};
