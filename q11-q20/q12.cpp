#include <vector>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int arrayMax = INT_MIN;
        int sum = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            if (sum > arrayMax) {
                arrayMax = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return arrayMax;
    }
};

int main() {
    vector <int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(nums) << endl;
}

