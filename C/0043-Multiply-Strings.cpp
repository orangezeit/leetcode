    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        if (num1.length() < num2.length()) {
            num1.swap(num2);
        }
        
        vector<char> vec1(num1.begin(), num1.end()), vec2(num2.begin(), num2.end());
        vector<int> product(num1.length()+num2.length()-1, 0);
        int p1(0), p2(0), q1(0), q2(0), k(0);
        string str;
        
        while (p1 <= p2) {
            for(int i = 0; i <= p2-p1; ++i) {
                product[k] += (vec1[p1+i]-'0') * (vec2[q2-i]-'0');
            }
            
            if (q2 < num2.length()-1) {
                p2++;
                q2++;
            } else if (p2 < num1.length()-1) {
                p1++;
                p2++;
            } else {
                p1++;
                q1++;
            }
            
            k++;
        }
        
        for (int i = product.size()-1; i >= 1; --i) {
            product[i-1] += product[i] / 10;
            product[i] %= 10;
        }
        
        for (int i = 0; i < product.size(); ++i) {
            str += to_string(product[i]);
        }
        
        return str;
    }
