class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            vector<int> emp;
            return emp;
        }
        if (matrix.size() == 1) {
            return matrix[0];
        }
        vector<int> diagonal(matrix.size() * matrix[0].size());

        if (matrix[0].size() == 1) {
            for (int i = 0; i < matrix.size(); ++i) {
                diagonal[i] = matrix[i][0];
            }
            return diagonal;
        } else {
            int i = 0;
            int j = 0;
            int k = 0;

            diagonal[k] = matrix[i][j];
            k++;
            //cout << i << " " << j << endl;
            while (i != matrix.size()-1 || j != matrix[0].size()-1) {
                if ( j == matrix[0].size()-1) {
                    i++;
                } else {
                    j++;
                }
                diagonal[k] = matrix[i][j];
                k++;
                //cout << i << "y" << j << endl;
                if (i == matrix.size()-1 && j == matrix[0].size()-1) {
                    break;
                }
                while (i != matrix.size()-1 && j != 0) {
                    i++;
                    j--;
                    diagonal[k] = matrix[i][j];
                    k++;
                    //cout << i << " " << j << endl;
                }
                /*
                if (i == matrix.size()-1 && j == matrix[0].size()-1) {
                    break;
                }
                */
                if (i == matrix.size()-1) {
                    j++;
                } else {
                    i++;
                }
                //cout << i << " " << j << endl;
                diagonal[k] = matrix[i][j];
                k++;

                while (i != 0 && j != matrix[0].size()-1) {
                    i--;
                    j++;
                    //cout << i << "x" << j << endl;
                    diagonal[k] = matrix[i][j];
                    k++;
                }

            }

            //cout << "a";
            //matrix[]
            return diagonal;
        }


        //if (i+1 < matrix)
    }
};
