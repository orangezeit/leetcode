/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y]
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int helper(ArrayReader &reader, int begin, int end, bool smaller=false) {
        while (begin + 1 < end) {
            int mid = (begin + end) / 2;
            int signal = reader.compareSub(begin, mid - 1, mid + (end - begin) % 2, end - 1);
            if (smaller) signal = -signal;
            if (signal == 1) {
                end = mid;
            } else if (signal == -1) {
                begin = mid + (end - begin) % 2;
            } else {
                return mid;
            }
        }
        return begin;
    };

    // follow-up 1: two largers, trinary search
    pair<int, int> helper2(ArrayReader &reader, int begin, int end) {

        int len = end - begin;
        int mid1 = len / 3 + (len % 3 ? 1 : 0);
        int mid2 = mid1 + len / 3 + len % 3;

        // compare [0, 1/3] (range a) with [1/3, 2/3] (range b)
        // compare [1/3, 2/3] (range b) with [2/3, 1] (range c)
        int signal1 = reader.compareSub(begin, len / 3 - 1, mid1, mid1 + len / 3 - 1);
        int signal2 = reader.compareSub(mid1, mid1 + len / 3 - 1, mid2, end - 1);

        // nine cases
        if (signal1 == 1) {
            if (signal2 == 1) {
                // a > b > c
                // one larger in a and one larger in b
                return {helper(reader, begin, len / 3), helper(reader, mid1, mid1 + len / 3)};
            } else if (signal2 == 0) {
                // a > b = c
                // at least one larger in a
                // move range b one step ahead or back to check
                if (len % 3 && reader.compareSub(begin, len / 3 - 1, mid1 - 1, mid1 + len / 3 - 2) == 0) {
                    return {helper(reader, begin, len / 3), len / 3};
                } else if (len % 3 == 2 && reader.compareSub(begin, len / 3 - 1, mid1 + 1, mid1 + len / 3) == 0) {
                    return {helper(reader, begin, len / 3), len / 3 * 2 + 1};
                } else {
                    return helper2(reader, begin, len / 3);
                }
            } else { // -1
                // a > b < c
                // one larger in a and one larger in c
                return {helper(reader, begin, len / 3), helper(reader, mid2, end)};
            }
        } else if (signal1 == 0) {
            if (signal2 == 1) {
                // a = b > c
                // one larger in a and one larger in b
                return {helper(reader, begin, len / 3), helper(reader, mid1, mid1 + len / 3)};
            } else if (signal2 == 0) {
                // a = b = c
                // assert that len % 3 == 2, otherwise raise error
                return {len / 3, len / 3 * 2 + 1};
            } else { // -1
                // a = b < c
                // at least one larger in c
                // move range b one step ahead or back to check
                if (len % 3 && reader.compareSub(mid2, end - 1, mid1 - 1, mid1 + len / 3 - 2) == 0) {
                    return {len / 3, helper(reader, mid2, end - 1)};
                } else if (len % 3 == 2 && reader.compareSub(mid2, end - 1, mid1 + 1, mid1 + len / 3) == 0) {
                    return {len / 3 * 2 + 1, helper(reader, mid2, end - 1)};
                } else {
                    return helper2(reader, mid2, end - 1);
                }
            }
        } else { // -1
            if (signal2 == 1) {
                // a < b > c
                // at least one larger in b
                // move range a one step back to check and range c one step ahead to check
                if (len % 3 && reader.compareSub(begin + 1, len / 3, mid1, mid1 + len / 3 - 1) == 0) {
                    return {len / 3, helper(reader, mid1, mid1 + len / 3 - 1)};
                } else if (len % 3 == 2 && reader.compareSub(mid1, mid1 + len / 3 - 1, mid2 - 1, end - 2) == 0) {
                    return {helper(reader, mid1, mid1 + len / 3 - 1), len / 3 * 2 + 1};
                } else {
                    return helper2(reader, mid1, mid1 + len / 3 - 1);
                }
            } else {
                // a < b = c or a < b < c
                return {helper(reader, mid1, mid1 + len / 3), helper(reader, mid2, end)};
            }
        }
        // should not return this result
        return {-1, -1};
    };

    // follow-up 2: one larger and one smaller, trinary search
    pair<int, int> helper3(ArrayReader &reader, int begin, int end) {
        if (end - begin < 3) return {-1, -1};
        int len = end - begin;
        int mid1 = len / 3 + (len % 3 ? 1 : 0);
        int mid2 = mid1 + len / 3 + len % 3;

        // compare [0, 1/3] (range a) with [1/3, 2/3] (range b)
        // compare [1/3, 2/3] (range b) with [2/3, 1] (range c)
        // compare [0, 1/3] (range a) with [2/3, 1] (range c)
        int signal1 = reader.compareSub(begin, len / 3 - 1, mid1, mid1 + len / 3 - 1);
        int signal2 = reader.compareSub(mid1, mid1 + len / 3 - 1, mid2, end - 1);
        int signal3 = reader.compareSub(begin, len / 3 - 1, mid2, end - 1);

        // nine cases
        if (signal1 == 1) {
            if (signal2 == 1) {
                // a > b > c
                // one larger in a and one smaller in c
                return {helper(reader, begin, len / 3), helper(reader, mid2, end, true)};
            } else if (signal2 == 0) {
                // a > b = c
                // one larger in a
                // one smaller in a or in the gaps among a, b, and c
                // move range b one step ahead or back to check
                if (len % 3 && reader.compareSub(mid1, mid1 + len / 3 - 1, mid1 - 1, mid1 + len / 3 - 2)) {
                    return {helper(reader, begin, len / 3), len / 3};
                } else if (len % 3 == 2 && reader.compareSub(mid1, mid1 + len / 3 - 1, mid1 + 1, mid1 + len / 3)) {
                    return {helper(reader, begin, len / 3), len / 3 * 2 + 1};
                } else {
                    return helper2(reader, begin, len / 3);
                }
            } else { // -1
                // a > b < c
                if (signal3 == 1) {
                    // if a > c, then b < c < a, one larger in a and one smaller in b
                    return {helper(reader, begin, len / 3), helper(reader, mid1, mid1 + len / 3, true)};
                } else if (signal3 == -1) {
                    // if a < c, then b < a < c, one larger in c and one smaller in b
                    return {helper(reader, mid2, end), helper(reader, mid1, mid1 + len / 3, true)};
                } else {
                    // if a = c, then b < a = c
                    // one smaller in b
                    // one larger in b or in the gaps among a, b, and c
                    // move range a back or range c ahead to check
                    if (len % 3 && reader.compareSub(begin, begin + len / 3 - 1, begin + 1, begin + len / 3)) {
                        return {helper(reader, mid1, mid1 + len / 3, true), len / 3};
                    } else if (len % 3 == 2 && reader.compareSub(mid2, end, mid2 - 1, end - 1)) {
                        return {helper(reader, mid1, mid1 + len / 3, true), len / 3 * 2 + 1};
                    } else {
                        return helper2(reader, mid1, mid1 + len / 3);
                    }
                }
            }
        } else if (signal1 == 0) {
            if (signal2 == 1) {
                // a = b > c
                // one smaller in c
                // one larger in c or in the gaps among a, b, and c
                // move range b one step ahead or back to check
                if (len % 3 && reader.compareSub(mid1, mid1 + len / 3 - 1, mid1 - 1, mid1 + len / 3 - 2)) {
                    return {helper(reader, mid2, end, true), len / 3};
                } else if (len % 3 == 2 && reader.compareSub(mid1, mid1 + len / 3 - 1, mid1 + 1, mid1 + len / 3)) {
                    return {helper(reader, mid2, end, true), len / 3 * 2 + 1};
                } else {
                    return helper2(reader, mid2, end);
                }
            } else if (signal2 == 0) {
                // the most complicated case!!!
                // a = b = c

                if (len % 3) {
                    // range a move back one step
                    int signal4 = reader.compareSub(begin, begin + len / 3 - 1, begin + 1, begin + len / 3);
                    // range b move ahead one step
                    int signal5 = reader.compareSub(mid1, mid1 + len / 3 - 1, mid1 - 1, mid1 + len / 3 - 2);
                    if (signal4 == 1) {
                        if (signal5 == 1) {
                            // assert that len % 3 = 2, otherwise raise error
                            return {len / 3, len / 3 * 2 + 1};
                        } else if (signal5 == 0) {
                            return {begin, helper(reader, begin + 1, begin + len / 3)};
                        } else {
                            // raise error
                        }
                    } else if (signal4 == 0) {
                        if (signal5 == 1) {
                            return {mid1 + len / 3 - 1, helper(reader, mid1, mid1 + len / 3 - 1)};
                        } else if (signal5 == 0) {
                            // unknown
                        } else {
                            return {mid1 + len / 3 - 1, helper(reader, mid1, mid1 + len / 3 - 1, true)};
                        }
                    } else { // -1
                        if (signal5 == 1) {
                            // raise error
                        } else if (signal5 == 0) {
                            return {begin, helper(reader, begin + 1, begin + len / 3, true)};
                        } else {
                            // assert that len % 3 == 2, otherwise raise error
                            return {len / 3, len / 3 * 2 + 1};
                        }
                    }
                }

                if (len % 3 == 2) {
                    // range b move back one step
                    int signal4 = reader.compareSub(mid1, mid1 + len / 3 - 1, mid1 + 1, mid1 + len / 3);
                    // range c move ahead one step
                    int signal5 = reader.compareSub(mid2, end, mid2 - 1, end - 1);
                    // either signal4 = 0 or signal5 = 0, otherwise raise error
                    if (signal4) {
                        if (signal4 == 1) {
                            return {mid1, helper(reader, mid1 + 1, mid1 + len / 3)};
                        } else { // -1
                            return {mid1, helper(reader, mid1 + 1, mid1 + len / 3, true)};
                        }
                    } else {
                        if (signal5 == 1) {
                            return {end - 1, helper(reader, mid2, end - 1)};
                        } else { // -1
                            return {end - 1, helper(reader, mid2, end - 1, true)};
                        }
                    }
                }

                // the worst case, since the large and the small are in the same interval
                // and it happens to be (larger + smaller = 2 * other)
                // have to check all intervals
                auto r1 = helper3(reader, begin, begin + len / 3);
                auto r2 = helper3(reader, mid1, mid1 + len / 3);
                auto r3 = helper3(reader, mid2, end);
                return r1.first >= 0 ? r1 : r2.first >= 0 ? r2 : r3;
            } else { // -1
                // a = b < c
                // one larger in c
                // one smaller in c or in the gaps among a, b, c
                // move range b one step ahead or back to check
                if (len % 3 && reader.compareSub(mid1, mid1 + len / 3 - 1, mid1 - 1, mid1 + len / 3 - 2)) {
                    return {helper(reader, mid2, end), len / 3};
                } else if (len % 3 == 2 && reader.compareSub(mid1, mid1 + len / 3 - 1, mid1 + 1, mid1 + len / 3)) {
                    return {helper(reader, mid2, end), len / 3 * 2 + 1};
                } else {
                    return helper2(reader, mid2, end);
                }
            }
        } else { // -1
            if (signal2 == 1) {
                // a < b > c
                if (signal3 == 1) {
                    // if a > c, then c < a < b, one larger in b and one smaller in c
                    return {helper(reader, mid1, mid1 + len / 3), helper(reader, mid2, end, true)};
                } else if (signal3 == -1) {
                    // if a < c, then a < c < b, one larger in b and one smaller in a
                    return {helper(reader, begin, begin + len / 3), helper(reader, mid2, end, true)};
                } else {
                    // if a = c, then a = c < b
                    // one larger in b
                    // one smaller in b or in the gaps among a, b, and c
                    // move range a back or range c ahead to check
                    if (len % 3 && reader.compareSub(begin, begin + len / 3 - 1, begin + 1, begin + len / 3)) {
                        return {helper(reader, mid1, mid1 + len / 3), len / 3};
                    } else if (len % 3 == 2 && reader.compareSub(mid2, end, mid2 - 1, end - 1)) {
                        return {helper(reader, mid1, mid1 + len / 3), len / 3 * 2 + 1};
                    } else {
                        return helper2(reader, mid1, mid1 + len / 3);
                    }
                }
                // at least one larger in b
                // move range a one step back to check and range c one step ahead to check
                if (len % 3 && reader.compareSub(begin + 1, len / 3, mid1, mid1 + len / 3 - 1) == 0) {
                    return {len / 3, helper(reader, mid1, mid1 + len / 3 - 1)};
                } else if (len % 3 == 2 && reader.compareSub(mid1, mid1 + len / 3 - 1, mid2 - 1, end - 2) == 0) {
                    return {helper(reader, mid1, mid1 + len / 3 - 1), len / 3 * 2 + 1};
                } else {
                    return helper2(reader, mid1, mid1 + len / 3 - 1);
                }
            } else if (signal2 == 0) {
                // a < b = c
                // one smaller in a
                // one larger in a or in the gaps among a, b, and c
                // move range b one step ahead or back to check
                if (len % 3 && reader.compareSub(mid1, mid1 + len / 3 - 1, mid1 - 1, mid1 + len / 3 - 2)) {
                    return {helper(reader, begin, len / 3, true), len / 3};
                } else if (len % 3 == 2 && reader.compareSub(mid1, mid1 + len / 3 - 1, mid1 + 1, mid1 + len / 3)) {
                    return {helper(reader, begin, len / 3, true), len / 3 * 2 + 1};
                } else {
                    return helper2(reader, begin, len / 3);
                }
                return {helper(reader, mid1, mid1 + len / 3), helper(reader, mid2, end)};
            } else {
                // a < b < c
                return {helper(reader, begin, len / 3, true), helper(reader, mid2, end)};
            }
        }
        // should not return this result
        return {-1, -1};
    };

    int getIndex(ArrayReader &reader) {
        return helper(reader, 0, reader.length());
    }
};
