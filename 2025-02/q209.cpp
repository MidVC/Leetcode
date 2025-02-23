#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 1, sum = nums[0], minlen = INT32_MAX;
        bool found = false;
        while (r < nums.size()) {
            if (sum >= target) {
                minlen = min(minlen, r-l);
                found = true;
                sum -= nums[l];
                l++;
            }
            else {
                sum += nums[r];
                r++;
            }
        }
        while (sum >= target) {
            minlen = min(minlen, r-l);
            found = true;
            sum -= nums[l];
            l++;
        }
        if (!found) return 0;
        return minlen;
    }
};

int main() {
    Solution s;
    vector<int> nums{2,3,1,2,4,3};
    cout << s.minSubArrayLen(7, nums) << endl;
}
