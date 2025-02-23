#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, bool> numsmap;
        for (auto n: nums) {numsmap[n] = false;}
        for (auto n: nums) {
            if (numsmap.find(n) != numsmap.end() && !numsmap[n]) {
                numsmap[n] = true;
                // Find the smallest and largest consecutive element
                int i = n-1, j = n+1;
                while (numsmap.find(i) != numsmap.end()) {
                    numsmap[i] = true;
                    i--;
                }
                while (numsmap.find(j) != numsmap.end()) {
                    numsmap[j] = true;
                    j++;
                }
                ans = max(ans, j-i-1);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums{100,4,200,1,3,2};
    cout << s.longestConsecutive(nums) << endl;
}
