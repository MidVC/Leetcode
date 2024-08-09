#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int index = 0;
        int len = nums.size();

        // change nums so that for values in [1, len] are stored to the [0, len-1] index, respectively
        while (index < len) {
            while (nums[index] > 0 && nums[index] != index + 1 && nums[index] <= len && nums[index] != nums[nums[index]-1]) {
                int temp = nums[index];
                nums[index] = nums[temp-1];
                nums[temp-1] = temp;
            }
            index++;
        }
        

        // check nums to see the smallest positive integer not present
        index = 0;
        while (index < len) {
            if (nums[index] != index+1) return index+1;
            index++;
        }
        return len+1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1};
    cout << s.firstMissingPositive(nums) << endl;
}

