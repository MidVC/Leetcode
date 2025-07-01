#include <vector>
using namespace std;

enum struct Direction {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0, top = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1;
        Direction dir = Direction::RIGHT;
        int x = 0, y = 0;

        while (left <= right && top <= bottom) {
            ans.push_back(matrix[y][x]);
            if (dir == Direction::RIGHT) {
                if (x >= right) {
                    dir = Direction::DOWN;
                    top += 1;
                    y += 1;
                }
                else { x += 1; }
            }
            else if (dir == Direction::DOWN) {
                if (y >= bottom) {
                    dir = Direction::LEFT;
                    right -= 1;
                    x -= 1;
                }
                else { y += 1; }
            }
            else if (dir == Direction::LEFT) {
                if (x <= left) {
                    dir = Direction::UP;
                    bottom -= 1;
                    y -= 1;
                }
                else { x -= 1; }
            }
            else {
                if (y <= top) {
                    dir = Direction::RIGHT;
                    left += 1;
                    x += 1;
                }
                else { y -= 1; }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution s;
    vector<int> ans = s.spiralOrder(matrix);
}
