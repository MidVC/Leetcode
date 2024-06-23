#include <cmath>
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isPositive = (dividend < 0 == divisor < 0);

        unsigned int absend = abs(dividend);
        unsigned int abssor = abs(divisor);
        unsigned int ans = 0;

        while (absend >= abssor) {
            unsigned int quotient = 0;
            while (absend > (abssor << (quotient + 1)) && (abssor << quotient) < 2147483648) {
                ++quotient;
            }
            ans += 1 << quotient;
            absend -= abssor << quotient;
        }

        if (isPositive && ans == 1 << 31) return INT_MAX;

        return isPositive ? ans : -ans;
    }
};

int main() {
    Solution s;
    cout << s.divide(-2147483648, -2147483648) << endl;
}
