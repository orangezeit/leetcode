private:
    unordered_map<string, string> encoded;  // long to short
    unordered_map<string, string> record;   // short to long
    string sample = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    void generateUrl(const string address, string& str) {
        str.clear();
        for (int i = 0; i < 6; ++i) {
            str += sample[rand() % 62];
        }
    }
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (encoded.find(longUrl) != encoded.end()) {
            return "http://tinyurl.com/" + encoded[longUrl];
        }
        
        string str;
        
        while (str.empty() || record.find(str) != record.end()) {
            generateUrl(longUrl, str);
        }
        
        record[str] = longUrl;
        encoded[longUrl] = str;
        
        return "http://tinyurl.com/" + str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return record[shortUrl.substr(19, 6)];
    }
