#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int i = 0, j = 1; // pointers to end of answer array and original array
        // find first duplicate
        for (; i < nums.size()-2; ++i) {
            if (nums[i] == nums[i+2]) break;
        }
        i += 1;
        j = i+2;
        
        while (j < nums.size()) {
            if (nums[i-1] != nums[j]) {
                nums[i+1] = nums[j];
                i++;
            }
            j++;
        }
        return i+1;
    }
};

int main() {
    Solution s;
    vector<int> v{1, 1, 1, 2, 2, 3};
    cout << s.removeDuplicates(v) << endl;
}