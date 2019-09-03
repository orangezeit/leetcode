#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>

/* 1,3,5,7
    20, 26, 27, 28,
    35, 38
    53
    66, 69, 70
    88*/

/// 0001
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> record;
    for (int i = 0; i < nums.size(); ++i)
        if (record.find(target - nums[i]) == record.end())
            record[nums[i]] = i;
        else
            return {record[target - nums[i]], i};
}

/// 0003
int lengthOfLongestSubstring(string s) {

    unordered_set<char> list;
    int maxL(0), l(0);

    for (int i = 0; i < s.length(); ++i) {
        if (list.find(s[i]) == list.end()) {
            list.insert(s[i]);
            l++;
        } else {
            maxL = max(maxL, l);
            while (s[i-l] != s[i]) {
                list.erase(s[i-l]);
                l--;
            }
        }
    }

    return max(maxL, l);
}

/// 0005
string convert(string s, int numRows) {

    if (numRows == 1) return s;

    string s2;
    string strs[numRows];

    int k(0);
    bool inverse(false);

    for (int i = 0; i < s.length(); ++i) {
        if (inverse) {
            strs[k--] += s[i];
            if (k == -1) {
                k += 2;
                inverse = false;
            }
        } else {
            strs[k++] += s[i];
            if (k == numRows) {
                k -= 2;
                inverse = true;
            }
        }
    }

    for (int i = 0; i < numRows; ++i) {
        s2 += strs[i];
    }

    return s2;
}

/// 0007
int reverseInteger(int x) {
    string str = to_string(x);
    reverse(str.begin(), str.end())
    if (x < 0) str.pop_back();
    return str.length() < 10 || str <= "2147483647" ? x < 0 ? -stoi(str) : stoi(str) : 0;
}

/// 0020
bool isValid(string s) {
    stack<char> brackets;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            brackets.push(s[i]);
        } else if (brackets.empty()) {
            return false;
        } else if (brackets.top() == '(' && s[i] == ')') {
            brackets.pop();
        } else if (brackets.top() == '[' && s[i] == ']') {
            brackets.pop();
        } else if (brackets.top() == '{' && s[i] == '}') {
            brackets.pop();
        } else {
            return false;
        }
    }

    return brackets.empty();
}

/// 0026
int removeDuplicates(vector<int>& nums) {
    nums.push_back(INT_MAX);
    int k(-1);
    for (int i = 0; i < nums.size() - 1; ++i)
        if (nums[i] != nums[i+1])
            nums[++k] = nums[i];
    return k;
}

/// 0027
int removeElement(vector<int>& nums, int val) {
    int k(0);
    for (int i = 0; i < nums.size(); ++i)
        if (nums[i] != val)
            nums[k++] = nums[i];
    return k;
}

/// 0028
int strStr(string haystack, string needle) {
    for (int i = 0; i < haystack.length() - needle.length() + 1; ++i)
        if (haystack.substr(i, needle.length()) == needle)
            return i;
    return -1;
}

/// 0035
int searchInsert(vector<int>& nums, int target) {
    int i = 0;
    int j = nums.size();
    if (target <= nums[0])
        return i;
    while (j - i > 1)
        target > nums[(i + j) / 2] ? i = (i + j) / 2 : j = (i + j) / 2;
    return j;
}

/// 0038
    string countAndSay(int n) {
        string str = "1";

        while (--n) {
            str += ' ';
            string newStr;
            int c(-1);

            for (int i = 0; i < str.length()-1; ++i)
                if (str[i] != str[i+1]) {
                    newStr += to_string(i-c) + str[i];
                    c = i;
                }

            str = newStr;
        }

        return str;
    }

/// 0053
int maxSubArray(vector<int>& nums) {
    int sum(nums[0]);

    for (int i = 1; i < nums.size(); ++i) {
        nums[i] = max(nums[i], nums[i-1] + nums[i]);
        sum = max(sum, nums[i]);
    }

    return sum;
}

/// 0066
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;

        while (digits[i] == 9) {
            digits[i--] = 0;
            if (i < 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }

        digits[i]++;
        return digits;
    }

/// 0069
    int mySqrt(int x) {
        int i(0), j(46341);

        while (j - i > 1) {
            int m = (i + j) / 2;
            x < m * m ? j = m : i = m;
        }

        return i;
    }
/// 0070
    int climbStairs(int n) {
        long j(1), k(1);
        for (int i = 0; i < n; ++i)
            i % 2 ? j += k : k += j;
        return n % 2 ? j : k;
    }

    /// 0088
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = (m--) + (n--) - 1;
        while (n >= 0 && m >= 0)
            nums1[i--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        while (n >= 0)
            nums1[i--] = nums2[n--];
    }

