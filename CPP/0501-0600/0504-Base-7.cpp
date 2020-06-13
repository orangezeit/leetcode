    string convertToBase7(int num) {
        if (num) {
            string str;
            bool negative(false);
            
            if (num < 0) {
                num = -num;
                negative = true;
            }
            
            while (num) {
                str += to_string(num % 7);
                num /= 7;
            }
            
            if (negative) {
                str += "-";
            }
            
            reverse(str.begin(), str.end());
            return str;
        } else {
            return "0";
        }
    }
