#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int closest = INT_MAX;
        int min_diff = INT_MAX;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                int diff = abs(sum - target);
                if (diff < min_diff) {
                    closest = sum;
                    min_diff = diff;

                    // End this program if the sum is exactly the target
                    if (sum == target) {
                        return closest;
                    }
                }

                // Check which direction to go
                if (sum < target) {
                    left++;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
                else {
                    right--;
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }

            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
        }

        return closest;
    }
};

int main() {
    vector<int> v = {-1,2,1,-4};
    int ans = Solution().threeSumClosest(v, 1);
    cout << ans << endl;
}