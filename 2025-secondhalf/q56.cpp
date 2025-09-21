#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        for (auto it = intervals.begin() + 1; it != intervals.end(); ++it) {
            if (prev[1] < (*it)[0]) {
                ans.push_back(prev);
                prev = *it;
            } else {
                prev[1] = max(prev[1], (*it)[1]);
            }
        }
        ans.push_back(prev);
        return ans;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10}, {15,18}};
    Solution s;
    vector<vector<int>> ans = s.merge(intervals);
}
