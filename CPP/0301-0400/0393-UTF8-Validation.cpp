class Solution {
public:
    string transform (int n) {
        string str;

        while (n > 1) {
            str += to_string(n % 2);
            n /= 2;
        }

        str += to_string(n);

        while (str.length() < 8) {
            str += "0";
        }

        for (int i = 0; i < str.length()/2; ++i) {
            swap(str[i], str[str.length()-i-1]);
        }

        return str;
    }

    bool validUtf8(vector<int>& data) {
        //for (int i = 0; i < data.size(); ++i) {
            //cout << transform(data[i]) << endl;
        //}
        if (data.size() == 0) {
            return true;
        }

        int k = 0;
        while (transform(data[0])[k] != '0') {
            k++;
        }
        //cout <<  k << endl;
        if (k == 0) {
            data.erase(data.begin());
            return validUtf8(data);
        } else if (k == 1 || k >= 5) {
            return false;
        } else if (data.size() < k) {
            return false;
        }

        for(int i = 1; i < k; ++i) {
                if (transform(data[i]).substr(0, 2) != "10") {
                    return false;
                }
        }
        data.erase(data.begin(), data.begin()+k);
        return validUtf8(data);
    }
};
