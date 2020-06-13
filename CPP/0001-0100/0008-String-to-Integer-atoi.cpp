class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        
        int i(0);
        while (str[i] == ' ') i++;
        bool negative(str[i] == '-');
        if (str[i] == '-' || str[i] == '+') i++;
        if (str[i] < '0' || str[i] > '9') return 0;
        
        string num;
        
        bool fn(false);
        while(i < str.length() && str[i] >= '0' && str[i] <= '9') {
            num += str[i++];
            if (num.back() != '0') fn = true;
            else if (!fn) num.pop_back();
            
        }
        
        if (negative && (num.length() > 10 || num.length() == 10 && num >= "2147483648"))
            return INT_MIN;
        else if (!negative && (num.length() > 10 || num.length() == 10 && num >= "2147483647"))
            return INT_MAX;
        else if (!num.empty())
            return (negative ? -1 : 1) * stoi(num);
        
        return 0;
    }
};
