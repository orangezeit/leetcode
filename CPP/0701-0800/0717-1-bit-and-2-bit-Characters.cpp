    bool isOneBitCharacter(vector<int>& bits) {
        int k = 0;
        while (k < bits.size() - 1) {
            bits[k] == 1 ? k += 2 : k++;
        }
        return k != bits.size();
    }
