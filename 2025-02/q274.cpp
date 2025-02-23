#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> buckets(citations.size()+1, 0);
        for (auto c: citations) {
            if (c >= citations.size()) buckets[citations.size()]++;
            else buckets[c]++;
        }
        int count = 0;
        for (int i = citations.size(); i >= 0; i--) {
            count += buckets[i];
            if (count >= i) return i;
        }
        return 0; 
    }
};

int main() {
    Solution s;
    // cout << s.sol() << endl;
}
