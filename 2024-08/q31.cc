#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the latest index i with nums[i] < nums[i+1]
        int latestIndex = -1;
        for (int i = nums.size()-2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                latestIndex = i;
                break;
            }
        }

        // reverse the array if all nums[i] >= nums[i+1]
        if (latestIndex == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find nums[i] < nums[i+1], get smallest nums[j] such that nums[j] > nums[i]
        int smallestNumIndex = latestIndex + 1;
        for (int i = smallestNumIndex+1; i < nums.size(); ++i) {
            if (nums[i] > nums[latestIndex] && nums[i] <= nums[smallestNumIndex])
                smallestNumIndex = i;
        }

        // swap nums[i] and nums[j], reverse subvector after i
        swap(nums[latestIndex], nums[smallestNumIndex]);
        reverse(nums.begin()+latestIndex+1, nums.end());

    }
};
