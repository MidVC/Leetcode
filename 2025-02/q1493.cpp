#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // if all items are 1
        bool flag = true;
        for (auto n : nums) {
            if (n == 0) {flag = false; break;}
        }
        if (flag) return nums.size()-1;


        // find the first subarray of 1's
        int i = 0;
        while (i < nums.size() && nums[i] == 0) {++i;}
        if (i == nums.size()) return 0;
        
        // store all subarrays
        bool indicator = 1; // 1 means currently in array of 1, 0 means 0
        int prev0len = 2; // count previous array of 1?
        int prevlen = 0, curlen = 1;
        int maxlen = 0;
        ++i;
        while (i < nums.size()) {
            if (nums[i] == 1) {
                if (indicator) curlen += 1;
                else {
                    indicator = 1;
                    prevlen = curlen;
                    curlen = 1;
                }
            }
            else {
                if (indicator) {
                    if (prev0len == 1) maxlen = max(maxlen, prevlen+curlen);
                    else maxlen = max(maxlen, curlen);
                    indicator = 0;
                    prev0len = 1;
                }
                else prev0len += 1;
            }
            ++i;
        }
        if (prev0len == 1 && indicator == 1) maxlen = max(maxlen, prevlen+curlen);
        else maxlen = max(maxlen, curlen);
        return maxlen;
    }
};

int main() {
    Solution s;
    vector<int> v{1,1,1};
    cout << s.longestSubarray(v) << endl;
}