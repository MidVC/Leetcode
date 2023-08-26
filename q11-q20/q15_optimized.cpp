#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    ans.push_back(triplet);
                    left++;
                    right--;

                    // Check and eliminate duplicates
                    while (left < right && nums[left] == triplet[1]) {
                        left++;
                    }
                    while (left < right && nums[right] == triplet[2]) {
                        right--;
                    }
                }
            }

            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
        }

        // Forgot to return LOL
        return ans;
    }
};

int main() {
    vector<int> v = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = Solution().threeSum(v);
    for (auto i : ans) {
        cout << i[0] << " " << i[1] << " " << i[2] << endl;
    }
}
