// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int k = 0;

        while (reader.get(k) != INT_MAX) {
            if (reader.get(k) == target)
                return k;
            k++;
        }

        return -1;
    }
};
