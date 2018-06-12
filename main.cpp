/*** A Simple Calculator ***/

/*************************************************************************
 *                                                                       *
 *    Only real numbers allowed                                          *
 *    5 arithmetic operations: + - * / ^                                 *
 *    15 special functions: sin(x) cos(x) tan(x) csc(x) sec(x) cot(x)    *
 *                          arcsin(x) arccos(x) arctan(x)                *
 *                          exp(x) log(x) abs(x)                         *
 *                          factorial(n) nPr(n,r) nCr(n,r)               *
 *    Can detect syntax and math errors from inputs and operations       *
 *                                                                       *
 *************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

double process (string str);

void precision (string p, int& k)
{
    int i;
    bool invalid(false);
    cout << ">> p: ";
    cin >> p;
    for (i = 0; i < p.length(); ++i) {
        if (p[i] <'0' || p[i] > '9') {
            invalid = true;
        }
    }

    while (invalid) {
        cin.ignore();
        cout << ">> Invalid precision" << endl;
        cout << ">> p: ";
        cin >> p;
        invalid = false;
        for (i = 0; i < p.length(); ++i) {
            if (p[i] < '0' || p[i] > '9' ) {
                invalid = true;
            }
        }
    }

    istringstream ss(p);
    ss >> k;
}

void calculateAgain (void)
{
    string str;   // input string
    string p;     // string precision
    int k;        // int precision
    bool d(true); // test if default

    cout << ">> ";
    getline(cin, str);

    while (str != "q") {
        if (str.empty()) {
            cout << ">> ";
            getline(cin, str);
        } else if (str == "d") {    // default precision
            d = true;
            cout << ">> ";
            getline(cin, str);
        } else if (str == "p") {    // reset precision
            d = false;
            precision(p, k);
            cin.ignore();
            cout << ">> ";
            getline(cin, str);
        } else {                    // direct calculation
            if (d) {
                cout << ">> " << setprecision(10) << process(str);
                cin.ignore();
                cout << ">> ";
                getline(cin, str);
            } else {
                cout << ">> " << fixed << setprecision(k) << process(str);
                cin.ignore();
                cout << ">> ";
                getline(cin, str);
            }
        }
    }

    cout << ">> End" << endl;       // quit the program
}

void bounds (double x) // check lower and upper bounds
{
    if (x > pow(10.0, 100.0)) {
        cout << ">> Math Error" << endl;
        atexit(calculateAgain); // run calculateAgain after exit
        exit(0); // result too large
    } else if (x < pow(0.1, 100.0)){
        x = 0;
    } // 0 if result too small
}

void arithEval (char op, double val1, double val2, double& result)
{
    if (op == '+') {
        result = val1 + val2;
    } else if (op == '-') {
        result = val1 - val2;
    } else if (op == '*') {
        result = val1 * val2;
    } else if (op == '/') {
        if (val2 != 0) {
	        result = val1 / val2;
	    } else {
	        cout << ">> Math Error" << endl;
	        atexit(calculateAgain); // run calculateAgain after exit
	        exit(0); // exit if the denominator is 0
	    }
    } else if (op == '^') {
        result = pow(val1, val2);
    }

    bounds(result);
}

double factorial (double val)
{
    double product(1.0);

    if (val < 0 || val != round(val)) {
        cout << ">> Math Error" << endl;
        atexit(calculateAgain); // run calculateAgain after exit
        exit(0); // exit if val is negative or non-integer
    } else if (val == 0) {
        return(1);
    } else {
        for (int i = 1; i <= round(val); ++i) {
            product *= i;
        }

        bounds(product);
        return(product);
    }
}

void specificFn (string specific, double val, double& result)
{
    if (specific == "sin") {
        result = sin(val);
    } else if (specific == "cos") {
        result = cos(val);
    } else if (specific == "tan") {
        result = tan(val);
    } else if (specific == "csc") {
        result = 1.0 / sin(val);
    } else if (specific == "sec") {
        result = 1.0 / cos(val);
    } else if (specific == "cot") {
        result = 1.0 / tan(val);
    } else if (specific == "arcsin") {
        result = asin(val);
    } else if (specific == "arccos") {
        result = acos(val);
    } else if (specific == "arctan") {
        result = atan(val);
    } else if (specific == "exp") {
        result = exp(val);
    } else if (specific == "log") {
        result = log(val);
    } else if (specific == "abs") {
        result = abs(val);
    } else if (specific == "factorial") {
        result = factorial(val);
    } else {
        cout << ">> Syntax Error" << endl;
        atexit(calculateAgain); // run calculateAgain after exit
        exit(0); // exit if specific not defined
    }

    bounds(result);
}

double permutation (double n, double r)
{
    return(factorial(n) / factorial(n - r));
}

double combination (double n, double r)
{
    return(factorial(n) / (factorial(r) * factorial(n - r)));
}

void centerEval (vector<char> charCenter, double& result)
{
    int i, j, k, n; // loop index
    vector<char> op;                                           // store operators
    vector<int> opPosition, numPosition, decimalPtPosition;    // store operator, digit and decimal point positions

    for (i = 0; i < charCenter.size(); ++i) {
        if (charCenter[i] == '+') {
            op.push_back('+');
            opPosition.push_back(i);  // store additions and their positions
        } else if (charCenter[i] == '-') {
            op.push_back('-');
            opPosition.push_back(i);  // store subtractions and their positions
        } else if (charCenter[i] == '*') {
            op.push_back('*');
            opPosition.push_back(i);  // store multiplications and their positions
        } else if (charCenter[i] == '/') {
            op.push_back('/');
            opPosition.push_back(i);  // store divisions and their positions
        } else if (charCenter[i] == '^') {
            op.push_back('^');
            opPosition.push_back(i);  // store powers and their positions
        } else if ((charCenter[i] >= '0' && charCenter[i] <= '9') || charCenter[i] == '.') {
            numPosition.push_back(i); // store digit positions (including decimal points)
        }

    }

    if (opPosition.size() + numPosition.size() != charCenter.size()) {
        cout << ">> Syntax Error" << endl;
        atexit(calculateAgain); // run calculateAgain after exit
        exit(0); // exit if illegitimate chars detected
    }

    if (numPosition.size() != 0) {
        for (i = 0; i < numPosition.size(); ++i) {
            if (charCenter.at(numPosition.at(i)) == '.') {
                decimalPtPosition.push_back(numPosition.at(i));
                // store decimal point positions
            }
        }
    }

    if (opPosition.size() != 0) {
        for (i = 0; i < opPosition.size() - 1; ++i) {
            if (opPosition.at(i+1) - opPosition.at(i) == 1) {
                cout << ">> Syntax Error" << endl;
                atexit(calculateAgain); // run calculateAgain after exit
                exit(0); // exit if consecutive operators detected
            }
        }
        for (i = 0; i < opPosition.size(); ++i) {
            if (opPosition.at(i) == charCenter.size() - 1) {
                cout << ">> Syntax Error" << endl;
                atexit(calculateAgain); // run calculateAgain after exit
                exit(0); // exit if an operator detected at the end of charCenter
            } else if (opPosition.at(i) == 0 && op.at(i) != '-' && op.at(i) != '+') {
                cout << ">> Syntax Error" << endl;
                atexit(calculateAgain); // run calculateAgain after exit
                exit(0); // exit if an operator detected at the beginning of charCenter
            } else if ((charCenter.at(opPosition.at(i)+1) < '0' ||
                        charCenter.at(opPosition.at(i)+1) > '9') &&
                        charCenter.at(opPosition.at(i)+1) != '(') {
                cout << ">> Syntax Error" << endl;
                atexit(calculateAgain); // run calculateAgain after exit
                exit(0); // exit if no number detected after an operator
            }
        }
    }

    if (decimalPtPosition.size() != 0) {
        if (decimalPtPosition.size() > 1) { // if there exist more than one decimal points
            for (i = 0; i < decimalPtPosition.size() - 1; ++i) {
                if (decimalPtPosition.at(i+1) - decimalPtPosition.at(i) == 1) {
                    cout << ">> Syntax Error" << endl;
                    atexit(calculateAgain); // run calculateAgain after exit
                    exit(0); // exit if consecutive decimal points detected
                }
            }
        }
        for (i = 0; i < decimalPtPosition.size(); ++i) {
            if (decimalPtPosition.at(i) == charCenter.size() - 1) {
                cout << ">> Syntax Error" << endl;
                atexit(calculateAgain); // run calculateAgain after exit
                exit(0); // exit if a decimal point detected at the end of charCenter
            } else if (charCenter.at(decimalPtPosition.at(i)+1) < '0' ||
                       charCenter.at(decimalPtPosition.at(i)+1) > '9') {
                cout << ">> Syntax Error" << endl;
                atexit(calculateAgain); // run calculateAgain after exit
                exit(0); // exit if no number detected after a decimal point
            }
        }
    }

    vector< vector<char> > charNumberGroup; // char digit matrix
    int numOfNum(0);                        // record the number of numbers
    vector<int> criticalPts;                // record critical points
    vector<int> lengths;                    // record the lengths of numbers
    int maxDigit(0);                        // record the max digit number

    if(numPosition.size() > 1) {
        for (i = 0; i < numPosition.size() - 1; ++i) {
            if (numPosition.at(i + 1) - numPosition.at(i) != 1){
                numOfNum++;
                criticalPts.push_back(i);
            }
        }
    }

    ++numOfNum;
    // calculate the number of numbers

    if (numOfNum == 1) {
        lengths.push_back(numPosition.size());
    } else {
        lengths.push_back (criticalPts.at(0) + 1);
        for (i = 0; i < criticalPts.size() - 1; ++i) {
            lengths.push_back (criticalPts.at(i + 1) - criticalPts.at(i));
        }
        lengths.push_back (numPosition.size() - criticalPts.at(criticalPts.size() - 1) - 1);
    } // create the lengths of numbers

    for (i = 0; i < lengths.size(); ++i) {
        if (maxDigit < lengths.at(i)) {
            maxDigit = lengths.at(i);
	    }
	} // calculate the max digit number

    charNumberGroup.resize(lengths.size());
    for (i = 0; i < lengths.size(); ++i) {
        charNumberGroup[i].resize(maxDigit);
	} // resize the char digit matrix

    i = 0;
    for (j = 0; j < lengths.size(); j++) {
	    for (k = 0; k < lengths.at(j); k++) {
            charNumberGroup[j][k] = charCenter.at(numPosition.at(i));
	        ++i;
	    }
	} // record the char digit matrix

    vector< vector<int> > numberGroup; // int digit matrix

    numberGroup.resize(lengths.size());
    for (i = 0; i < lengths.size(); ++i) {
        numberGroup[i].resize(maxDigit);
	} // resize the int digit matrix

    for (i = 0; i < lengths.size(); ++i) {
        for (j = 0; j < maxDigit; ++j) {
            if (charNumberGroup[i][j] == '.') {
                numberGroup[i][j] = -1;
		    } else if (charNumberGroup[i][j] >= '0' && charNumberGroup[i][j] <= '9') {
		        numberGroup[i][j] = charNumberGroup[i][j] - '0';
		    }
	    }
	} // transfer char to int

    int countDecimalPt;

    for (i = 0; i < lengths.size(); ++i) {
        countDecimalPt = 0;
        for (j = 0; j < maxDigit; ++j) {
            if (numberGroup[i][j] == -1) {
                ++countDecimalPt; //calculate number of decimal points
            }
        }
        if (countDecimalPt > 1) {
            cout << ">> Syntax Error" << endl;
            atexit(calculateAgain); // run calculateAgain after exit
            exit(0); // exit if two decimal points detected in a number
        }
    }

    vector<int> decimalRow, decimalColumn; // record the rows and columns that have decimal points
    vector<int> line; // the line vector

    for (i = 0; i < lengths.size(); ++i) {
        line.push_back(i); // initially record each line in the line vector
    }

    for (i = 0; i < lengths.size(); ++i) {
        for (j = 0; j < lengths.at(i); ++j) {
	        if (numberGroup[i][j] == -1) {
		        decimalRow.push_back(i);
		        decimalColumn.push_back(j); //record index
		    }
	    }
	}

	for (i = 0; i < lengths.size(); ++i) {
        for (j = 0; j < decimalRow.size(); ++j) {
            if (i == decimalRow.at(j)) {
                line.erase(remove(line.begin(), line.end(), i), line.end());
                // remove decimal lines from the line vector
            }
        }
	}

    vector<double> tempeval, eval; // record temporary and final evaluations
    int powerIndex;                // record power index
    double sum;                    // record temporary sums

    i = 0;
    if (decimalRow.size() == 0 ) {
        // extreme case 1: none have decimals
        for (j = 0; j < line.size(); ++j) {
            if (i == line.at(j)) {
                powerIndex = lengths.at(i);
	            for (k = 0; k < lengths.at(i); ++k) {
	                tempeval.push_back(pow(10, powerIndex - 1) * numberGroup[i][k]);
		            --powerIndex;
		        }
	            sum = 0.0;
	            for (k = 0; k < tempeval.size(); ++k) {sum += tempeval.at(k);}
	            eval.push_back(sum);
	            tempeval.clear();
	            ++i;
            }
        }
    } else if (line.size() == 0) {
        // extreme case 2: all have decimals
        for (j = 0; j < decimalRow.size(); ++j) {
            if (i == decimalRow.at(j)) {
                powerIndex = decimalColumn.at(j);
                for (k = 0; k < lengths.at(i); ++k) {
	                if (k != decimalColumn.at(j)) {
	                    tempeval.push_back(pow(10, powerIndex - 1) * numberGroup[i][k]);
		                --powerIndex;
	                } else {tempeval.push_back(0.0);}
		        }
	            sum = 0.0;
	            for (k = 0; k < tempeval.size(); ++k) {sum += tempeval.at(k);}
	            eval.push_back(sum);
	            tempeval.clear();
                ++i;
            }
        }
    } else {
        for (i = 0; i < lengths.size(); ++i){
            for (j = 0; j < decimalRow.size(); ++j) {
                if (i == decimalRow.at(j)) {
                // if decimal points included
                    powerIndex = decimalColumn.at(j);
                    for (n = 0; n < lengths.at(i); ++n) {
                        if (n != decimalColumn.at(j)) {
                            tempeval.push_back(pow (10, powerIndex - 1) * numberGroup[i][n]);
                            --powerIndex;
                        } else {tempeval.push_back(0.0);}
                    }
                    sum = 0.0;
                    for (n = 0; n < tempeval.size(); ++n) {sum += tempeval.at(n);}
                    eval.push_back(sum);
                    tempeval.clear();
                }
            }
            for (k = 0; k < line.size(); ++k) {
                if (i == line.at(k)) {
                // if decimal points not included
                    powerIndex = lengths.at(i);
                    for (n = 0; n < lengths.at(i); ++n) {
                        tempeval.push_back(pow(10, powerIndex - 1) * numberGroup[i][n]);
                        --powerIndex;
                    }
                    sum = 0.0;
                    for (n = 0; n < tempeval.size(); ++n) {sum += tempeval.at(n);}
                    eval.push_back(sum);
                    tempeval.clear();
                }
            }
        }
    }

    if (op.size() == 0) {
        result = eval.at(0);    // no operators in the brackets
    } else {
        vector<int> opRank;     // desired operators labeled 1 and others 0
        vector<int> opSelect;   // record relative positions of desired operators

        for (i = 0; i < op.size(); i++) {
            if (op.at(i) == '^') {
                opRank.push_back(1);      // '^' as index 1
            } else {opRank.push_back(0);} // others as index 0
        }

        for (i = 0; i < opRank.size(); i++) {
            if (opRank.at(i) == 1) {opSelect.push_back(i);} // record relative positions of '^'
        }

        double tempCal; // restore the temporary result

        if (op.size() == eval.size()) {                  // special case ('+' or '-' in the beginning)
            for (i = opSelect.size() - 1; i >= 0; --i) { // evaluate from the right to the left
                arithEval('^', eval.at(opSelect.at(i) - 1), eval.at(opSelect.at(i)), tempCal);
                // evaluate between two numbers and store in tempCal
                op.erase(op.begin() + opSelect.at(i));                   // erase that operator
                eval.erase(eval.begin() + opSelect.at(i) - 1);           // erase the first number
                eval.erase(eval.begin() + opSelect.at(i) - 1);           // erase the second number
                eval.insert(eval.begin() + opSelect.at(i) - 1, tempCal); // insert tempCal
                tempCal = 0.0; // clear tempCal after each evaluation
            }
        } else {
            for (i = opSelect.size() - 1; i >= 0; --i) { // evaluate from the right to the left
                arithEval('^', eval.at(opSelect.at(i)), eval.at(opSelect.at(i) + 1), tempCal);
                // evaluate between two numbers and store in tempCal
                op.erase(op.begin() + opSelect.at(i));               // erase that operator
                eval.erase(eval.begin() + opSelect.at(i));           // erase the first number
                eval.erase(eval.begin() + opSelect.at(i));           // erase the second number
                eval.insert(eval.begin() + opSelect.at(i), tempCal); // insert tempCal
                tempCal = 0.0; // clear tempCal after each evaluation
            }
        }

        opRank.clear();
        opSelect.clear();
        // clear opRank and opSelect to use later

        for (i = 0; i < op.size(); i++) {
            if (op.at(i) == '*' || op.at(i) == '/') {
                opRank.push_back(1);      // '*' and '/' as index 1
            } else {opRank.push_back(0);} // others as index 0
        }

        for (i = 0; i < opRank.size(); i++) {
            if (opRank.at(i) == 1) {opSelect.push_back(i);} // record relative positions of '*' and '/'
        }

        if (op.size() == eval.size()) {             // special case ('+' or '-' in the beginning)
            for (i = 0; i < opSelect.size(); ++i) { // evaluate from the left to the right
                if (op.at(opSelect.at(i)) == '*') {
                    arithEval('*', eval.at(opSelect.at(i) - 1), eval.at(opSelect.at(i)), tempCal);
                } else {
                    arithEval('/', eval.at(opSelect.at(i) - 1), eval.at(opSelect.at(i)), tempCal);
                } // evaluate between two numbers and store in tempCal

                op.erase(op.begin() + opSelect.at(i));               // erase that operator
                if (opSelect.at(i) == 0) {
                    op.insert(op.begin() + opSelect.at(i), '+');     // replace with '+' if no left
                } else if (op.at(opSelect.at(i) - 1) == '+') {
                    op.insert(op.begin() + opSelect.at(i), '+');     // replace with '+' if the left is '+'
                } else if (op.at(opSelect.at(i) - 1) == '-') {
                    op.insert(op.begin() + opSelect.at(i), '-');     // replace with '-' if the left is '-'
                }
                eval.erase(eval.begin() + opSelect.at(i) - 1);           // erase the first number
                eval.erase(eval.begin() + opSelect.at(i) - 1);           // erase the second number
                eval.insert(eval.begin() + opSelect.at(i) - 1, tempCal); // insert tempCal on the right
                eval.insert(eval.begin() + opSelect.at(i) - 1, 0.0);     // insert 0 on the left
                tempCal = 0.0; // clear tempCal after each evaluation
            }
        } else {
            for (i = 0; i < opSelect.size(); ++i) { // evaluate from the left to the right
                if (op.at(opSelect.at(i)) == '*') {
                    arithEval('*', eval.at(opSelect.at(i)), eval.at(opSelect.at(i) + 1), tempCal);
                } else {
                    arithEval('/', eval.at(opSelect.at(i)), eval.at(opSelect.at(i) + 1), tempCal);
                } // evaluate between two numbers and store in tempCal

                op.erase(op.begin() + opSelect.at(i));               // erase that operator
                if (opSelect.at(i) == 0) {
                    op.insert(op.begin() + opSelect.at(i), '+');     // replace with '+' if no left
                } else if (op.at(opSelect.at(i) - 1) == '+') {
                    op.insert(op.begin() + opSelect.at(i), '+');     // replace with '+' if the left is '+'
                } else if (op.at(opSelect.at(i) - 1) == '-') {
                    op.insert(op.begin() + opSelect.at(i), '-');     // replace with '-' if the left is '-'
                }
                eval.erase(eval.begin() + opSelect.at(i));           // erase the first number
                eval.erase(eval.begin() + opSelect.at(i));           // erase the second number
                eval.insert(eval.begin() + opSelect.at(i), tempCal); // insert tempCal on the right
                eval.insert(eval.begin() + opSelect.at(i), 0.0);     // insert 0 on the left
                tempCal = 0.0; // clear tempCal after each evaluation
            }
        }

        if (eval.size() == op.size()) {       // special case ('+' or '-' in the beginning)
            eval.insert(eval.begin(), 0);
            for (i = 0; i < op.size(); ++i) { // evaluate from the left to the right
                if (op.at(i) == '+') {
                    arithEval('+', eval.at(i), eval.at(i+1), tempCal);
                } else {
                    arithEval('-', eval.at(i), eval.at(i+1), tempCal);
                }
                // evaluate between two numbers and store in tempCal

                op.erase(op.begin() + i);                // erase that operator
                op.insert(op.begin() + i, '+');          // replace with '+'
                eval.erase(eval.begin() + i);            // erase the first number
                eval.erase(eval.begin() + i);            // erase the second number
                eval.insert(eval.begin() + i, tempCal);  // insert tempCal on the right
                eval.insert(eval.begin() + i, 0.0);      // insert 0 on the left
                tempCal = 0.0; // clear tempCal after each evaluation
            }
            result = eval.at(eval.size() - 1);
        } else {
            for (i = 0; i < op.size(); ++i) { // evaluate from the left to the right
                if (op.at(i) == '+') {
                    arithEval('+', eval.at(i), eval.at(i + 1), tempCal);
                } else {
                    arithEval('-', eval.at(i), eval.at(i + 1), tempCal);
                }
                // evaluate between two numbers and store in tempCal

                op.erase(op.begin() + i);                // erase that operator
                op.insert(op.begin() + i, '+');          // replace with '+'
                eval.erase(eval.begin() + i);            // erase the first number
                eval.erase(eval.begin() + i);            // erase the second number
                eval.insert(eval.begin() + i, tempCal);  // insert tempCal on the right
                eval.insert(eval.begin() + i, 0.0);      // insert 0 on the left
                tempCal = 0.0; // clear tempCal after each evaluation
            }
            result = eval.at(eval.size() - 1);
        }
    }
}

void findInnerBrackets (vector<int>& leftBrackets, vector<int>& rightBrackets, vector<int>& bracketPair, int& countBrackets)
{

    int i, j; // loop index
    vector<int> combinedBrackets; // combine left bracket index and right bracket index
    vector<int> bracketPairTemp;  // record the inner bracket pair temporarily

    for (i = 0; i < leftBrackets.size(); ++i) {combinedBrackets.push_back(leftBrackets.at(i));}
    for (i = 0; i < rightBrackets.size(); ++i) {combinedBrackets.push_back(rightBrackets.at(i));}
    sort(combinedBrackets.begin(), combinedBrackets.end());
    // create a sorted combined bracket set

    int k(0);
    for (i = 0; i < combinedBrackets.size(); ++i) {
        for (j = 0; j < leftBrackets.size(); ++j) {
            if (combinedBrackets.at(i) == leftBrackets.at(j)) {++k;}
        }

        for (j = 0; j < rightBrackets.size(); ++j) {
            if (combinedBrackets.at(i) == rightBrackets.at(j)) {--k;}
        }

        if (k < 0) {
            cout << ">> Syntax Error" << endl;
            atexit(calculateAgain); // run calculateAgain after exit
            exit(0); // exit if brackets not in correct orders
        }
    }

    for (i = 0; i < countBrackets; ++i) {
	    for (j = 0; j < countBrackets; ++j) {
	        if (leftBrackets.at(i) < rightBrackets.at(j)) {
	            bracketPairTemp.push_back(leftBrackets.at(i));
	            bracketPairTemp.push_back(rightBrackets.at(j));
	        }
	    }
	} // record all bracket pairs

	for (i = 0; i < bracketPairTemp.size(); i += 2) {
        if (find(combinedBrackets.begin(), combinedBrackets.end(), bracketPairTemp.at(i + 1)) -
        find(combinedBrackets.begin(), combinedBrackets.end(), bracketPairTemp.at(i)) == 1) {
            bracketPair.push_back(bracketPairTemp.at(i));
            bracketPair.push_back(bracketPairTemp.at(i+1));
        }
    } // select all legitimate bracket pairs

	bracketPair.resize(2); // select the inner bracket pair with the least left index

	leftBrackets.erase (find(leftBrackets.begin(), leftBrackets.end(), bracketPair.at(0)));
    rightBrackets.erase (find(rightBrackets.begin(), rightBrackets.end(), bracketPair.at(1)));
    // remove selected brackets from  the original lists
}

void breakBrackets (vector<char> charVector, vector<char>& charLeft, vector<char>& charCenter,
                    vector<char>& charRight, vector<int> bracketPair, bool& special, string& multistr)
{

    int i; // loop index

    if(bracketPair.at(0) != 0) {
        special = (charVector.at(bracketPair.at(0) - 1) != '+') && (charVector.at(bracketPair.at(0) - 1) != '-') &&
                  (charVector.at(bracketPair.at(0) - 1) != '*') && (charVector.at(bracketPair.at(0) - 1) != '/') &&
                  (charVector.at(bracketPair.at(0) - 1) != '^') && (charVector.at(bracketPair.at(0) - 1) != '(');
    } // test if the special function exits

    if (special) {
        int critical(-1);
        for (i = bracketPair.at(0) - 1; i >=0; --i) {
            if (charVector.at(i) < 'A' || (charVector.at(i) > 'Z' && charVector.at(i) < 'a') || charVector.at(i) > 'z') {
                critical = i;
                break;
            }
            multistr.append(1, charVector.at(i));
        }
        multistr = string(multistr.rbegin(), multistr.rend());

        if (critical >= 0) {
            for (i = 0; i <= critical; ++i){
                charLeft.push_back(charVector.at(i));
            }
        } // record the char list on the left

        if (bracketPair.at(1) != charVector.size() - 1) {
            for (i = 0; i < charVector.size() - bracketPair.at(1) - 1; ++i){
                charRight.push_back(charVector.at(bracketPair.at(1) + i + 1));
            }
        } // record the char list on the right

        if (bracketPair.at(1) - bracketPair.at(0) == 1) {
            cout << ">> Syntax Error" << endl;
            atexit(calculateAgain); // run calculateAgain after exit
            exit(0); // exit if nothing in the brackets
        } else {
            for (i = 0; i < bracketPair.at(1) - bracketPair.at(0) - 1; ++i) {
                charCenter.push_back(charVector.at(bracketPair.at(0) + i + 1));
            }
        } // record the char list in the brackets

    } else {
        if (bracketPair.at(0) != 0) {
            for (i = 0; i < bracketPair.at(0) ; ++i){
                charLeft.push_back(charVector.at(i));
            }
        } // record the char list on the left

        if (bracketPair.at(1) != charVector.size() - 1) {
            for (i = 0; i < charVector.size() - bracketPair.at(1) - 1; ++i){
                charRight.push_back(charVector.at(bracketPair.at(1) + i + 1));
            }
        } // record the char list on the right

        if (bracketPair.at(1) - bracketPair.at(0) == 1) {
            cout << ">> Syntax Error" << endl;
            atexit(calculateAgain); // run calculateAgain after exit
            exit(0); // exit if nothing in the brackets
        } else {
            for (i = 0; i < bracketPair.at(1) - bracketPair.at(0) - 1; ++i) {
                charCenter.push_back(charVector.at(bracketPair.at(0) + i + 1));
            }
        } // record the char list in the brackets
    }
}

void evalTransfer (double eval, vector<char>& charEval) // double to char vector
{
    int i;                             // loop index
    ostringstream ss;                  // string stream

    ss << eval;                        // input double
    string str = ss.str();             // output string

    /**  0 if eval too small (underflow) **/
    /**  string str = to_string(eval);   **/
    for (i = 0; i < str.size(); ++i) {
        if (str.at(i) == 'e') {
            cout << ">> Design Error" << endl;
            atexit(calculateAgain); // run calculateAgain after exit
            exit(0); // exit if str in scientific notation
        }
    }

    charEval.resize(str.size()); // resize vector given string
    for (i = 0; i < str.size(); ++i) {charEval.at(i) = str.at(i);} // transfer string to char vector
}

void concatenateChar (vector<char>& charLeft, vector<char>& charEval, vector<char>& charRight, vector<char>& charVector)
{
    charVector.clear(); // clear the original charVector
    charVector.reserve(charLeft.size() + charEval.size() + charRight.size());  // reserve the size for the new charVector
    charVector.insert(charVector.end(), charLeft.begin(), charLeft.end());     // insert charLeft
    charVector.insert(charVector.end(), charEval.begin(), charEval.end());     // insert charEval
    charVector.insert(charVector.end(), charRight.begin(), charRight.end());   // insert charRight
    charLeft.clear();   // clear charLeft
    charEval.clear();   // clear charEval
    charRight.clear();  // clear charRight
}

void bracketIndex (vector<char> charVector, vector<int>& leftBrackets, vector<int>& rightBrackets, int& countBrackets)
{
    leftBrackets.clear();
    rightBrackets.clear();
    // clear previous index

    for (int i = 0; i < charVector.size(); ++i) {
        if (charVector.at(i) == '(') {leftBrackets.push_back(i);}
        if (charVector.at(i) == ')') {rightBrackets.push_back(i);}
    } // record current index
    countBrackets = leftBrackets.size(); // record current number of bracket pairs
}

int stringBrackets (string str) // count bracket pairs in string
{
    int num(0);

    for (int i = 0; i < str.length(); ++i) {if (str.at(i) == '(') {++num;}}
    return(num);
}

bool bracketComplete (string str) // test if brackets in pairs in string
{
    bool complete(false);
    int left(0), right(0);

    for (int i = 0; i < str.size(); ++i) {
        if (str.at(i) == '(') {++left;}
        if (str.at(i) == ')') {++right;}
    }
    if (left == right) {complete = true;}
    return(complete);
}

void leftPow (double eval, vector<char>& charLeft, vector<char>& charRight, vector<char>& charVector, string& charTemp)
{
    int i, j; // loop index
    double temp, resultTemp;  // temporary evaluations
    bool powerFind(false);    // find if '^' exists in charTemp
    vector<char> leftPart, rightPart, charResult; // temporary char vectors

    i = charLeft.size() - 2;
    while (i >= 0) {
        if (charLeft.at(i) == '+' || charLeft.at(i) == '-' || charLeft.at(i) == '*' || charLeft.at(i) == '/' || charLeft.at(i) == '(') {break;}
        charTemp.push_back(charLeft.at(i));
        --i;
    }
    reverse(charTemp.begin(), charTemp.end());
    charLeft.erase(charLeft.end() - charTemp.size() - 1, charLeft.end());
    for (i = charTemp.size() - 1; i >= 0; --i) {
        if (charTemp.at(i) == '^') {
            powerFind = true;
            for (j = 0; j <= i; ++j) {leftPart.push_back(charTemp.at(j));}
            for (j = 0; j < charTemp.size() - i - 1; ++j) {rightPart.push_back(charTemp.at(i + j + 1));}
            break;
        }
    }
    if (!powerFind) {for (i = 0; i < charTemp.size(); ++i) {rightPart.push_back(charTemp.at(i));}}
    centerEval (rightPart, temp);
    arithEval('^', temp, eval, resultTemp);
    evalTransfer (resultTemp, charResult);
    for (i = 0; i < charResult.size(); ++i) {leftPart.push_back(charResult.at(i));}
    concatenateChar(charLeft, leftPart, charRight, charVector);
}

void rightPow (vector<char>& charRight, string& charTemp, int& countBrackets)
{
    int i(1);

    while (i < charRight.size()) {
        if (charRight.at(i) == '+' || charRight.at(i) == '-'  || charRight.at(i) == '*' || charRight.at(i) == '/' || charRight.at(i) == ')') {
            if (bracketComplete(charTemp)) {break;}
        }
        charTemp.push_back(charRight.at(i));
        ++i;
    }
    charRight.erase(charRight.begin(), charRight.begin() + charTemp.size() + 1);
    countBrackets -= stringBrackets(charTemp);
}

void leftSide (char j, double eval, string& charTemp,
               vector<char>& charLeft, vector<char>& charEval, vector<char>& charRight, vector<char>& charVector)
{
    int i;
    bool pm(true);

    if (j == '+') {
        charLeft.pop_back();
        concatenateChar(charLeft, charEval, charRight, charVector);
    } else if (j == '-') {
        charLeft.pop_back();
        charEval.erase(charEval.begin());
        charLeft.push_back('+');
        concatenateChar(charLeft, charEval, charRight, charVector);
    } else if (j == '*' || j == '/') {
        charEval.erase(charEval.begin());
        for (i = charLeft.size() - 1; i >= 0; --i) {
            if (charLeft.at(i) == '+' || charLeft.at(i) == '-') {
                if (charLeft.at(i) == '+') {charLeft.at(i) = '-';} else {charLeft.at(i) = '+';}
                pm = false;
                break;
            }
        }
        if (pm) {charLeft.insert(charLeft.begin(), '-');}
        concatenateChar(charLeft, charEval, charRight, charVector);
    } else {
        leftPow(eval, charLeft, charRight, charVector, charTemp);
    }
}

void bothSides (char j, double eval, string& charTemp,
                vector<char>& charLeft, vector<char>& charEval, vector<char>& charRight, vector<char>& charVector)
{
    int i;
    bool pm(true);

    if (j == '(') {
        concatenateChar(charLeft, charEval, charRight, charVector);
    } else if (j == '+') {
        charLeft.pop_back();
        concatenateChar(charLeft, charEval, charRight, charVector);
    } else if (j == '-') {
        charLeft.pop_back();
        charEval.erase(charEval.begin());
        charLeft.push_back('+');
        concatenateChar(charLeft, charEval, charRight, charVector);
    } else if (j == '*' || j == '/') {
        charEval.erase(charEval.begin());
        for (i = charLeft.size() - 1; i >= 0; --i) {
            if (charLeft.at(i) == '+' || charLeft.at(i) == '-') {
                if (charLeft.at(i) == '+') {charLeft.at(i) = '-';} else {charLeft.at(i) = '+';}
                pm = false;
                break;
            }
        }
        if (pm) {charLeft.insert(charLeft.begin(), '-');}
        concatenateChar(charLeft, charEval, charRight, charVector);
    } else if (j == '^') {
        leftPow(eval, charLeft, charRight, charVector, charTemp);
    }
}

void resultTest (double resultTemp, int& countBrackets, vector<char>& charLeft, vector<char>& charRight, vector<char>& charVector)
{
    vector<char> charResult;

    if (resultTemp < 0) {
        evalTransfer (resultTemp, charResult);
        charResult.insert(charResult.begin(), '(');
        charResult.insert(charResult.end(), ')');
        countBrackets++;
        concatenateChar(charLeft, charResult, charRight, charVector);
    } else {
        evalTransfer (resultTemp, charResult);
        concatenateChar(charLeft, charResult, charRight, charVector);
    }
}

double process (string str)
{
    string strNoSpace;
    int i;

    for (i = 0; i < str.length(); ++i){
        if (str.at(i) != ' '){strNoSpace.push_back(str.at(i));}
    } // remove space

    char charList[strNoSpace.length()];
    strNoSpace.copy(charList, strNoSpace.length());
    vector<char> charVector;
    charVector.insert(charVector.begin(), charList, charList + sizeof(charList));
    // create initial charVector

    for (i = 1; i < charVector.size(); ++i) {
        if (charVector.at(i) == '(' && (charVector.at(i - 1) == ')' || (charVector.at(i - 1) >= '0' && charVector.at(i - 1) <= '9'))) {
            charVector.insert(charVector.begin() + i, '*');
        }
    } // insert missed '*'

    for (i = 1; i < charVector.size(); ++i) {
        if (charVector.at(i - 1) == '+' && charVector.at(i) == '+') {
            charVector.at(i - 1) = '?';
        } else if (charVector.at(i - 1) == '+' && charVector.at(i) == '-') {
            charVector.at(i - 1) = '?';
        } else if (charVector.at(i - 1) == '-' && charVector.at(i) == '+') {
            charVector.at(i - 1) = '?';
            charVector.at(i) = '-';
        } else if (charVector.at(i - 1) == '-' && charVector.at(i) == '-') {
            charVector.at(i - 1) = '?';
            charVector.at(i) = '+';
        }
    }

    for (i = 0; i < charVector.size(); ++i) {
        charVector.erase(remove(charVector.begin(), charVector.end(), '?'), charVector.end());
    } // reduce '+' and '-'

    for (i = 0; i < charVector.size() - 1; ++i) {
        if(charVector.at(i) == ')'     && charVector.at(i + 1) != ')' && charVector.at(i + 1) != '^' &&
           charVector.at(i + 1) != '+' && charVector.at(i + 1) != '-' && charVector.at(i + 1) != '*' && charVector.at(i + 1) != '/') {
            cout << ">> Syntax Error" << endl;
            atexit(calculateAgain); // run calculateAgain after exit
            exit(0);
        }
    } // exit if illegitimate operators after ')'

    int countLefts(0), countRights(0);

    for (i = 0; i < charVector.size(); ++i) {
        if (charVector.at(i) == '(') {countLefts++;}
        if (charVector.at(i) == ')') {countRights++;}
    }

    if (countLefts != countRights) {
        cout << ">> Syntax Error" << endl;
        atexit(calculateAgain); // run calculateAgain after exit
        exit(0);
    } // exit if number of left brackets not equal to number of right brackets

    // variable declaration for general calculation
    int countBrackets, comma; // count for bracket pairs, comma location for nPr and nCr
    double n, r;              // set objects and selections for nPr and nCr
    vector<int> leftBrackets, rightBrackets, bracketPair;
    vector<char> charLeft, charCenter, charRight, charEval, leftNum, rightNum;
    double eval, speciEval;   // temporary evaluations
    bool special(false);      // test if special function exists
    string multistr;          // string for special functions

    // variable declaration for negative outcomes in brackets
    char j, k;                            // j for last char of charLeft, k for first char of charRight
    string charTemp;                      // string for recursion
    double temp, interTemp, resultTemp;   // temporary evaluations

    bracketIndex(charVector, leftBrackets, rightBrackets, countBrackets);

    if (countBrackets == 0) {
        centerEval(charVector, eval);
        return eval;
    } else {
        do {
            bracketIndex(charVector, leftBrackets, rightBrackets, countBrackets);
            findInnerBrackets(leftBrackets, rightBrackets, bracketPair, countBrackets);
            charCenter.clear();
            breakBrackets(charVector, charLeft, charCenter, charRight, bracketPair, special, multistr);
            bracketPair.clear();

            if (multistr != "nPr" && multistr != "nCr") {centerEval (charCenter, eval);}
            if (special) {
                if (multistr == "nPr" || multistr == "nCr") {
                    for (i = 0; i < charCenter.size(); ++i) {if (charCenter.at(i) == ',') {comma = i;}}
                    for (i = 0; i < comma; ++i) {leftNum.push_back(charCenter.at(i));}
                    for (i = comma + 1; i < charCenter.size(); ++i) {rightNum.push_back(charCenter.at(i));}
                    centerEval(leftNum, n);
                    centerEval(rightNum, r);
                    if (multistr == "nPr") {speciEval = permutation(n, r);} else {speciEval = combination(n, r);}
                } else {specificFn(multistr, eval, speciEval);}

                evalTransfer(speciEval, charEval);
                if (speciEval < 0) {
                    j = '\0';
                    k = '\0';
                    if (charLeft.size() != 0) {j = charLeft.at(charLeft.size() - 1);}
                    if (charRight.size() != 0) {k = charRight.at(0);}
                    if(j == '\0' && k == '\0') {
                        concatenateChar(charLeft, charEval, charRight, charVector);
                    } else if (j == '\0') {
                        if (k != '^') {
                            concatenateChar(charLeft, charEval, charRight, charVector);
                        } else {
                            rightPow(charRight, charTemp, countBrackets);
                            temp = process(charTemp);
                            if (temp != round(temp)) {
                                cout << ">> Math Error" << endl;
                                atexit(calculateAgain); // run calculateAgain after exit
                                exit(0); // exit if power to the negative is non-integer
                            }
                            arithEval('^', speciEval, temp, resultTemp);
                            charEval.clear();
                            evalTransfer (resultTemp, charEval);
                            concatenateChar(charLeft, charEval, charRight, charVector);
                        }
                    } else if (k == '\0') {
                        leftSide(j, speciEval, charTemp, charLeft, charEval, charRight, charVector);
                    } else {
                        if (k != '^') {
                            bothSides(j, speciEval, charTemp, charLeft, charEval, charRight, charVector);
                        } else if (j != '^') {
                            rightPow(charRight, charTemp, countBrackets);
                            temp = process(charTemp);
                            if (temp != round(temp)) {
                                cout << ">> Math Error" << endl;
                                atexit(calculateAgain); // run calculateAgain after exit
                                exit(0); // exit if power to the negative is non-integer
                            }
                            arithEval('^', speciEval, temp, resultTemp);
                            resultTest(resultTemp, countBrackets, charLeft, charRight, charVector);
                        } else if (j == '^') {
                            rightPow(charRight, charTemp, countBrackets);
                            temp = process(charTemp);
                            if (temp != round(temp)) {
                                cout << ">> Math Error" << endl;
                                atexit(calculateAgain); // run calculateAgain after exit
                                exit(0); // exit if power to the negative is non-integer
                            }
                            arithEval('^', speciEval, temp, interTemp);
                            charTemp.clear();
                            leftPow(interTemp, charLeft, charRight, charVector, charTemp);
                        }
                    }
                    charTemp.clear();
                } else {concatenateChar(charLeft, charEval, charRight, charVector);}
            } else {
                evalTransfer(eval, charEval);
                if (eval < 0) {
                    j = '\0';
                    k = '\0';
                    if (charLeft.size() != 0) {j = charLeft.at(charLeft.size() - 1);}
                    if (charRight.size() != 0) {k = charRight.at(0);}
                    if(j == '\0' && k == '\0') {
                        concatenateChar(charLeft, charEval, charRight, charVector);
                    } else if (j == '\0') {
                        if (k != '^') {
                            concatenateChar(charLeft, charEval, charRight, charVector);
                        } else {
                            rightPow(charRight, charTemp, countBrackets);
                            temp = process(charTemp);
                            if (temp != round(temp)) {
                                cout << ">> Math Error" << endl;
                                atexit(calculateAgain); // run calculateAgain after exit
                                exit(0); // exit if power to the negative is non-integer
                            }
                            arithEval('^', eval, temp, resultTemp);
                            charEval.clear();
                            evalTransfer(resultTemp, charEval);
                            concatenateChar(charLeft, charEval, charRight, charVector);
                        }
                    } else if (k == '\0') {
                        leftSide(j, eval, charTemp, charLeft, charEval, charRight, charVector);
                    } else {
                        if (k != '^') {
                            bothSides(j, eval, charTemp, charLeft, charEval, charRight, charVector);
                        } else if (j != '^') {
                            rightPow(charRight, charTemp, countBrackets);
                            temp = process(charTemp);
                            if (temp != round(temp)) {
                                cout << ">> Math Error" << endl;
                                atexit(calculateAgain); // run calculateAgain after exit
                                exit(0); // exit if power to the negative is non-integer
                            }
                            arithEval('^', eval, temp, resultTemp);
                            resultTest(resultTemp, countBrackets, charLeft, charRight, charVector);
                        } else if (j == '^') {
                            rightPow(charRight, charTemp, countBrackets);
                            temp = process(charTemp);
                            if (temp != round(temp)) {
                                cout << ">> Math Error" << endl;
                                atexit(calculateAgain); // run calculateAgain after exit
                                exit(0); // exit if power to the negative is non-integer
                            }
                            arithEval('^', eval, temp, interTemp);
                            charTemp.clear();
                            leftPow(interTemp, charLeft, charRight, charVector, charTemp);
                        }
                    }
                    charTemp.clear();
                } else {concatenateChar(charLeft, charEval, charRight, charVector);}
            }
            special = false;
            multistr.clear();
        } while (countBrackets > 1);
        centerEval(charVector, eval);
        return(eval);
    }
}

void calculate (string str, string p)
{
    int k;        // int precision
    bool d(true); // test if default

    cout << endl;
    cout << ">> Start" << endl;
    cout << ">> ";
    getline(cin, str);

    while (str != "q") {
        if (str.empty()) {
            cout << ">> ";
            getline(cin, str);
        } else if (str == "d") {    // default precision
            d = true;
            cout << ">> ";
            getline(cin, str);
        } else if (str == "p") {    // reset precision
            d = false;
            precision(p, k);
            cin.ignore();
            cout << ">> ";
            getline(cin, str);
        } else {                    // direct calculation
            if (d) {
                cout << ">> " << setprecision(10) << process(str); /** Problem **/
                cin.ignore();
                cout << ">> ";
                getline(cin, str);
            } else {
                cout << ">> " << fixed << setprecision(k) << process(str);
                cin.ignore();
                cout << ">> ";
                getline(cin, str);
            }
        }
    }

    cout << ">> End" << endl;       // quit the program
}

int main()
{
    string str; // input string
    string p;   // for precision
    calculate(str, p);
    return(0);
}
