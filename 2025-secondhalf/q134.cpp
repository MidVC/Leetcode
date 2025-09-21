#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int lowestNet = 0;
        int lowestIndex = 0;
        int netCost = 0;
        int i = 0;
        for (i; i < gas.size()-1; ++i) {
            netCost = netCost + gas[i] - cost[i];
            if (netCost < lowestNet) {
                lowestNet = netCost;
                lowestIndex = i+1;
            }
        }
        netCost = netCost + gas[i] - cost[i];
        if (netCost < 0) return -1;
        return lowestIndex;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // Solution s;
    // vector<int> ans = s.spiralOrder(matrix);
}
