class Solution {
public:
    vector<string> split_content(string path) {
        path += ' ';
        vector<string> strs;
        bool tail = false;
        int k(0);

        for (int i = 0; i < path.length(); ++i) {
            if (path[i] == ' ') {
                strs.push_back(path.substr(k, i - k));
                k = i + 1;
                if (tail) strs.push_back("");
                tail = true;
            }
        }

        strs[0] += '/';

        for (int i = 1; i < strs.size(); i += 2) {
            for (int j = 0; j < strs[i].length(); ++j) {
                if (strs[i][j] == '(') {
                    strs[i+1] = strs[i].substr(j + 1, strs[i].length() - j - 2);
                    strs[i] = strs[0] + strs[i].substr(0, j);
                    break;
                }
            }
        }

        return strs;
    }

    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> drive;

        for(int i = 0; i < paths.size(); ++i) {
            vector<string> v = split_content(paths[i]);

            for (int k = 2; k < v.size(); k += 2) {
                drive[v[k]].push_back(v[k - 1]);
            }
        }

        vector<vector<string>> ans;

        for (auto it = drive.begin(); it != drive.end(); ++it) {
            if (it->second.size() == 1) continue;
            ans.push_back(it->second);
        }

        return ans;
    }
};
