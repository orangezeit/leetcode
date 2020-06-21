class Solution {
public:
    string predictPartyVictory(string senate) {

        int r = 0;
        int d = 0;
        int n = 0;
        bool enter;

        for (int i = 0; i < senate.length(); ++i) {
            if (senate[i] == 'R') {
                r++;
            } else {
                d++;
            }
        }

        while (r != 0 && d != 0) {
            for (int i = 0; i < senate.length(); ++i) {
                enter = false;

                if (senate[i] == 'R') {
                    for (int j = i; j < senate.length(); ++j) {
                        if (senate[j] == 'D') {
                            senate.erase(j,1);
                            d--;
                            enter = true;
                            break;
                        }
                    }

                    if (!enter) {
                        for (int j = 0; j <= i; ++j) {
                            if (senate[j] == 'D') {
                                senate.erase(j,1);
                                d--;
                                break;
                            }
                        }
                    }
                } else if (senate[i] == 'D') {
                    for (int j = i; j < senate.length(); ++j) {
                        if (senate[j] == 'R') {
                            senate.erase(j,1);
                            r--;
                            enter = true;
                            break;
                        }
                    }

                    if (!enter) {
                        for (int j = 0; j <= i; ++j) {
                            if (senate[j] == 'R') {
                                senate.erase(j,1);
                                r--;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (r == 0) {
            return "Dire";
        } else {
            return "Radiant";
        }
    }
};
