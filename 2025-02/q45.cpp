#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        if (nums[0] >= nums.size()) return 1;
        int lastfar = 0, far = nums[0], cur = 0, step = 1;
        while (far < nums.size()-1) {
            int remfar = far;
            for (int i = lastfar+1; i <= remfar; ++i) {
                far = max(far, i + nums[i]);
            }
            lastfar = remfar;
            step++;
        }
        return step;
    }
};

int main() {
    Solution s;
    // cout << s.sol() << endl;
}
