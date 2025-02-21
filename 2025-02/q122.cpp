#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 0; i < prices.size()-1; ++i) {
            if (prices[i] < prices[i+1]) ans += prices[i+1] - prices[i];
        }
        return ans;
    }
};

int main() {
    Solution s;
    // cout << s.sol() << endl;
}
