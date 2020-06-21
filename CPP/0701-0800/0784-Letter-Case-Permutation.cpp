class Solution {
public:
    void permutationHelper(string S, vector<string>& permutations, string permutation) {

        if (S.length() == 0) {
            permutations.push_back(permutation);
        } else {

            if (S[0] >= '0' && S[0] <= '9') {
                permutation += S[0];
                S.erase(0,1);

                permutationHelper(S, permutations, permutation);

            } else {
                char c = S[0];
                permutation += S[0];
                S.erase(0,1);

                permutationHelper(S, permutations, permutation);

                permutation.pop_back();
                S.insert(0,1,c);

                if (S[0] >= 'a' && S[0] <= 'z') {
                    S[0] -= 32;
                } else {
                    S[0] += 32;
                }

                permutation += S[0];
                S.erase(0,1);

                permutationHelper(S, permutations, permutation);

                permutation.pop_back();
                S.insert(0,1,c);
            }
        }
    }
    vector<string> letterCasePermutation(string S) {
        string permutation;
        vector<string> permutations;

        permutationHelper(S, permutations, permutation);
        return permutations;
    }
};
