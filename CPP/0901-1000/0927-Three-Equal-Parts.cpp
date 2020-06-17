class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int c(0);
        for (const int& a: A) c += a;
        if (!c) return vector<int>({0, (int)A.size() - 1});
        else if (c % 3) return {-1, -1};

        bool meetOne(false);
        int i(0), j(A.size() - 1), si(0), sj(0), zeros(0);
        while (si < c / 3) {
            si += A[i++];
        }
        i--;

        while (sj < c / 3) {
            if (A[j] == 1) meetOne = true;
            if (A[j] == 0 && !meetOne) zeros++;
            sj += A[j--];
        }
        int z(zeros);
        while (z--)
            if (A[++i])
                return {-1, -1};

        while (A[j] == 0) {j--;} //j--
        j++;
        z = zeros;

        while (z--)
            if (A[j++])
                return {-1, -1};

        string sa, sb, sc;

        int k(0);
        while(A[k] == 0) k++;
        while (k <= i) sa += ('0' + A[k++]);
        while(A[k] == 0) k++;
        while (k <= j-1) sb += ('0' + A[k++]);
        while(A[k] == 0) k++;
        while (k < A.size()) sc += ('0' + A[k++]);

        return sa == sb && sb == sc ? vector<int>({i, j}) : vector<int>({-1, -1});
    }
};
