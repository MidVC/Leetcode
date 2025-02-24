#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) return vector<int>{l+1, r+1};
            else if (numbers[l] + numbers[r] > target) r--;
            else l++;
        }
        return vector<int>(1);
    }
};

int main() {
    Solution s;
    // cout << s.sol() << endl;
}
