class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        pair<int, string> info;
        vector<pair<int, string>> infos;
        int num;
        string domain;
        bool found = false;

        for (int i = 0; i < cpdomains.size(); ++i) {
            for (int j = 0; j < cpdomains[i].length(); ++j) {
                if (cpdomains[i][j] == ' ') {
                    num = stoi(cpdomains[i].substr(0, j));
                    domain = cpdomains[i].substr(j+1, cpdomains[i].length()-j-1);


                    if (infos.size() == 0) {
                        info.first = num;
                        info.second = domain;
                        infos.push_back(info);
                    } else {
                        for (int k = 0; k < infos.size(); k++) {
                            if (infos[k].second == domain) {
                                infos[k].first += num;
                                found = true;
                                break;
                            }
                        }

                        if (!found) {
                            info.first = num;
                            info.second = domain;
                            infos.push_back(info);
                        }
                    }
                    found = false;

                } else if (cpdomains[i][j] == '.') {
                    domain = cpdomains[i].substr(j+1, cpdomains[i].length()-j-1);
                    if (infos.size() == 0) {
                        info.first = num;
                        info.second = domain;
                        infos.push_back(info);
                    } else {
                        for (int k = 0; k < infos.size(); k++) {
                            if (infos[k].second == domain) {
                                infos[k].first += num;
                                found = true;
                                break;
                            }
                        }

                        if (!found) {
                            info.first = num;
                            info.second = domain;
                            infos.push_back(info);
                        }
                    }
                    found = false;
                }


            }
        }
        //cout << infos.size();
        vector<string> combine(infos.size());
        for (int i = 0; i < infos.size(); ++i) {
            combine[i] = to_string(infos[i].first) + " " + infos[i].second;

        }

        return combine;
    }
};
