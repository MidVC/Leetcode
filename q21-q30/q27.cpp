#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;
        while (left <= right) {
            if (nums[left] != val) {
                ++left;
                ++count;
            }
            else {
                if (nums[right] != val) {
                    int temp = nums[left];
                    nums[left] = nums[right];
                    nums[right] = temp;
                    ++left;
                    --right;
                    ++count;
                }
                else --right;
            }
        }

        return count;
    }
};