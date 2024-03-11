class Solution {

public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // sort the nums

        sort(nums.begin(), nums.end());

 

        // eliminate more than 4 duplicate

        vector<int> mynums;

        int count = 1;

        int lastNum = nums[0];

 

        // O(n^3)

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); ++i) {

            for (int j = i+1; j < nums.size(); ++j) {

                int low = j + 1;

                int high = nums.size() - 1;

                while (low < high) {

                    long int value = (long int)(target) - nums[i] - nums[j] - nums[low] - nums[high];

                    if (value < 0) --high;

                    else if (value > 0) ++low;

                    else {

                        if (find(ans.begin(), ans.end(), vector<int>{nums[i], nums[j], nums[low], nums[high]}) == ans.end() )

                            ans.push_back(vector<int>{nums[i], nums[j], nums[low], nums[high]});

                        ++low;

                        --high;

                    }

                }

            }

        }

 

        return ans;

    }

};
