#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int water = 0;
        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                if (height[left] > leftMax) leftMax = height[left];
                else {
                    if (height[left] < min(leftMax, rightMax)) water += min(leftMax, rightMax) - height[left];
                }
            }
            else {
                right--;
                if (height[right] > rightMax) rightMax = height[right];
                else {
                    if (height[right] < min(leftMax, rightMax)) water += min(leftMax, rightMax) - height[right];
                }
            }
        }
        return water;
    }
};