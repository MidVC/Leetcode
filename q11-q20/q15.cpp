#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        int len = nums.size();

        for (int i = 0; i < len; i++) {
          int j = i + 1;
          int k = len - 1;
          while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                s.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
            else if (sum < 0) {
                j++;
            }
            else{
                k--;
            }
          }
        }

        vector<vector<int>> ans;
        for(auto triples: s) {
            ans.push_back(triples);
        }
        
        return ans;
    }
};