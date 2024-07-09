#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        // use binary search to find the rightmost value
        int indexR = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                indexR = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else right = mid - 1;
        }

        // check if target is found
        if (indexR == -1) return {-1, -1};

        // find the leftmost target
        left = 0;
        right = nums.size() - 1;
        int indexL = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                indexL= mid;
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else right = mid - 1;
        }

        return {indexL, indexR};
    }
};
