class Solution {
public:
    int partitionDisjoint(vector<int>& A) {

        map<int, int> m1, m2;

        for (const int& i : A) {
            m2[i]++;
        }

        for (int i = 0; i < A.size(); ++i) {
            m1[A[i]]++;
            if (!(--m2[A[i]]))
                m2.erase(A[i]);
            if (m1.rbegin()->first <= m2.begin()->first) return i + 1;
        }

        return -1;
    }
};
