#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate;
        for (auto n: nums) {
            if (count == 0) {
                candidate = n;
                count++;
            }
            else {
                if (candidate == n) count++;
                else count--;;
            }
        }
        return candidate;
    }
};

int main() {
    Solution s;
    // cout << s.sol() << endl;
}
