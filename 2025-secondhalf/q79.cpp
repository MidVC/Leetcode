#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> taken(m, vector<bool>(n, false));
                    taken[i][j] = true;
                    if (dfs(taken, board, word, 1, i, j)) return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<bool>> &taken, const vector<vector<char>> &board, const string &word, int index, int x, int y) {
        if (index >= word.size()) return true;
        // search in 4 directions
        for (auto dir : directions) {
            int newX = x + dir.first, newY = y + dir.second;
            if (canUse(taken, newX, newY) && board[newX][newY] == word[index]) {
                taken[newX][newY] = true;
                if (dfs(taken, board, word, index+1, newX, newY)) return true;
                taken[newX][newY] = false;
            }
        }
        return false;
    }
    bool canUse(vector<vector<bool>> &taken, int x, int y) {
        if (x < 0 || x >= taken.size() || y < 0 || y >= taken[0].size()) return false;
        return !(taken[x][y]);
    }

    const vector<pair<int, int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
};

int main() {
    vector<vector<char>> matrix = {{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}};
    Solution s;
    bool ans = s.exist(matrix, "abcced");
    cout << ans << endl;
}
