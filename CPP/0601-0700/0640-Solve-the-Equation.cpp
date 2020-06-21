class Solution {
public:
    void simplify(vector<string> strs, int& num, int& unknown){

        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i].at(strs[i].length()-1) != 'x') {
                num = num + stoi(strs[i]);
            } else {
                if (strs[i].substr(0, strs[i].length()-1).empty()) {
                    ++unknown;
                } else if (strs[i].substr(0, strs[i].length()-1) == "+") {
                    ++unknown;
                } else if (strs[i].substr(0, strs[i].length()-1) == "-") {
                    --unknown;
                } else {
                    unknown = unknown + stoi(strs[i].substr(0, strs[i].length()-1));
                }
            }
        }
    }

    string solveEquation(string equation) {
        vector<string> left, right;
        string temp;
        int i = 0;
        int lnum(0), rnum(0), lunknown(0), runknown(0);

        while (equation.at(i) != '=') {
            while (equation.at(i) != '+' && equation.at(i) != '-' && equation.at(i) != '=') {
                if(i != 0) {
                    if(equation.at(i-1) == '+' || equation.at(i-1) == '-') {temp.push_back(equation.at(i-1));}
                }
                temp.push_back(equation.at(i));
                i++;
            }
            if(temp.size() != 0){left.push_back(temp);}
            temp.clear();
            if(equation.at(i) != '='){i++;}
        }

        i++;

        while (i < equation.length()) {
            while (equation.at(i) != '+' && equation.at(i) != '-') {
                if(equation.at(i-1) == '+' || equation.at(i-1) == '-') {temp.push_back(equation.at(i-1));}
                temp.push_back(equation.at(i));
                i++;
                if(i == equation.length()) {break;}
            }
            if(temp.size() != 0){right.push_back(temp);}
            temp.clear();
            i++;
        }

        simplify(left, lnum, lunknown);
        simplify(right, rnum, runknown);

        if (lunknown != runknown) {
            return "x=" + to_string((rnum-lnum) / (lunknown-runknown));
        } else if (lnum == rnum) {
            return "Infinite solutions";
        } else {
            return "No solution";
        }


    }
};
