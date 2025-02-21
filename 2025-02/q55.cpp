#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = nums[0], cur = 1;
        while (cur < nums.size() && cur <= far) {
            far = max(far, cur+nums[cur]);
            cur++;
        }
        if (cur < nums.size()) return false;
        return true;
    }
};

int main() {
    Solution s;
    // cout << s.sol() << endl;
}
