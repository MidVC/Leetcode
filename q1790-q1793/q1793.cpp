#include <vector>
#include <iostream>
using namespace std;


int maximumScore(vector<int>& nums, int k) {
    int i = k;
    int j = k;
    int min = nums[k];
    int maxScore = nums[k];
    int len = nums.size();
    while (i > 0 || j < len - 1) {
        if (i == 0) {
            j++;
            min = min < nums[j] ? min : nums[j];
            if (maxScore < min * (j - i + 1))  maxScore = min * (j - i + 1);
            continue;
        }
        if (j == len - 1) {
            i--;
            min = min < nums[i] ? min : nums[i];
            if (maxScore < min * (j - i + 1))  maxScore = min * (j - i + 1);
            continue;
        }
        if (nums[i - 1] > nums[j + 1]) {
            i--;
            min = min < nums[i] ? min : nums[i];
            if (maxScore < min * (j - i + 1))  maxScore = min * (j - i + 1);
        }
        else {
            j++;
            min = min < nums[j] ? min : nums[j];
            if (maxScore < min * (j - i + 1))  maxScore = min * (j - i + 1);
        }

    }
    return maxScore;
}

int main() {
    vector<int> nums = {1,4,3,7,4,5};
    cout << maximumScore(nums, 3) << endl;
}


