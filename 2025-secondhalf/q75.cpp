#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for (auto it : nums) {
            if (it == 0) count0++;
            else if (it == 1) count1++;
            else count2++;
        }
        int i = 0;
        for (i; i < count0; ++i) {
            nums[i] = 0;
        }
        for (i; i < count0 + count1; ++i) {
            nums[i] = 1;
        }
        for (i ; i < count0 + count1 + count2; ++i) {
            nums[i] = 2;
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // Solution s;
    // vector<int> ans = s.spiralOrder(matrix);
}
