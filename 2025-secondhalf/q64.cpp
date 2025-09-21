#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT32_MAX));
        // First row + first column
        int  colsum = 0, rowsum = 0;
        for (int i = 0; i < m; ++i) {
            colsum += grid[i][0];
            dp[i][0] = colsum;
        }
        for (int j = 0; j < n; ++j) {
            rowsum += grid[0][j];
            dp[0][j] = rowsum;
        }
        // DP process
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // Solution s;
    // vector<int> ans = s.spiralOrder(matrix);
}
