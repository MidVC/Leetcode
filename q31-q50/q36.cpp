#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    // calculate which block is this cell at
    int getBlockNum(int row, int col) {
        return (row/3)*3 + col/3;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, bool>> rows(9);
        vector<unordered_map<char, bool>> cols(9);
        vector<unordered_map<char, bool>> blocks(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    // find if it already exists in the row
                    auto it = rows[i].find(board[i][j]);
                    if (it != rows[i].end()) return false;
                    rows[i][board[i][j]] = true;

                    // find if it already exists in the col
                    it = cols[j].find(board[i][j]);
                    if (it != cols[j].end()) return false;
                    cols[j][board[i][j]] = true;

                    // find if it already exists in the block
                    int block_num = getBlockNum(i, j);
                    it = blocks[block_num].find(board[i][j]);
                    if (it != blocks[block_num].end()) return false;
                    blocks[block_num][board[i][j]] = true;
                }
            }
        }
        return true;
    }
};
