/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int guessMajority(ArrayReader &reader) {
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        int n(reader.length()), ans(0), s1(1), s2(0), x(reader.query(0, 1, 2, 3));
        bool b(false);
        for (int i = 4; i < n; ++i) {
            if (x == reader.query(0, 1, 2, i)) s1++;
            else {
                ans = i;
                s2++;
                if (i == 4) b = true;
            }
        }
        x == reader.query(1, 2, 3, 4) ^ b ? s1++ : s2++;
        x == reader.query(0, 2, 3, 4) ^ b ? s1++ : s2++;
        x == reader.query(0, 1, 3, 4) ^ b ? s1++ : s2++;
        return s1 > n / 2 ? 3 : s2 > n / 2 ? ans : -1;
    }
};
