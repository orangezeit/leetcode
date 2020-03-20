class Solution {
public:
    void reverse(basic_string<char>::iterator begin, basic_string<char>::iterator end) {
        while (begin < end) swap(*(begin++), *(--end));
    }

    int reverse(int x) {
        string str(to_string(x));
        reverse(str.begin(), str.end());
        if (x < 0) str.pop_back();
        return str.length() < 10 || str <= "2147483647" ? (x < 0 ? -1 : 1) * stoi(str) : 0;
    }
};
