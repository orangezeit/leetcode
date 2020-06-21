class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes = {".-","-...","-.-.","-..",".","..-.",
                                "--.","....","..",".---","-.-",".-..",
                                "--","-.","---",".--.","--.-",".-.",
                                "...","-","..-","...-",".--","-..-","-.--","--.."};
        string temp;
        vector<string> morses(words.size());

        for(int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].length(); ++j) {
                temp = temp + codes[words[i].at(j)-'a'];
            }
            morses[i] = temp;
            temp.clear();
        }

        sort(morses.begin(), morses.end());
        return distance(morses.begin(), unique(morses.begin(), morses.end()));
    }
};
