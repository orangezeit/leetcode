    string fractionToDecimal(long int numerator, long int denominator) {
        if (numerator == 0) {
            return "0";
        }
        
        string str;
        bool negative(false);
        
        if (numerator < 0) {
            negative = !negative;
            numerator = -numerator;
        }
        
        if (denominator < 0) {
            negative = !negative;
            denominator = -denominator;
        }
        
        if (negative) {
            str += "-";
        }
        
        str += to_string(numerator / denominator);
        numerator = (numerator % denominator) * 10;
        
        if (numerator) {
            str += ".";
            unordered_map<int, int> res;
            int k(str.length());
            
            while (res.find(numerator) == res.end() && numerator != 0) {
                res[numerator] = k;
                str += (numerator / denominator + '0');
                numerator = (numerator % denominator) * 10;
                k++;
            }
            
            if (numerator) {
                str.insert(res[numerator], 1, '(');
                str += ')';
            }
        }
        
        return str;
    }
