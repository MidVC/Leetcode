#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int maxprice = prices[prices.size()-1];
        for (int i = prices.size()-2; i >= 0; i--) {
            maxprofit = max(maxprofit, maxprice - prices[i]);
            maxprice = max(maxprice, prices[i]);
        }
        return maxprofit;
    }
};

int main() {
    Solution s;
    // cout << s.sol() << endl;
}
