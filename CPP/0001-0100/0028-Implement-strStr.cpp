
    int strStr(string haystack, string needle) {
        auto it = haystack
        for (int i = 0; i < haystack.length() - needle.length() + 1; ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }

        return -1;
    }
