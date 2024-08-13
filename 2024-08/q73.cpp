#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool flag1 = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                flag1 = true;
                continue;
            }
        }

        bool flag2 = false;
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) {
                flag2 = true;
                continue;
            }
        }

        // store 0 information (hash) at row 1 and col 1
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // read stored 0 information to change the matrix
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        // restore and change row 1 and col 1
        if (flag1) {
            for (int i = 0; i < matrix.size(); ++i) matrix[i][0] = 0;
        }

        if (flag2) {
            for (int j = 0; j < matrix[0].size(); ++j) matrix[0][j] = 0;
        }

    }
};