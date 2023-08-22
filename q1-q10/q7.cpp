#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int num = x;
        while (num) {
            if (rev > INT_MAX/10 || rev < INT_MIN/10 ) return 0;
            rev = rev * 10 + num % 10;
            num = num / 10;
        }
        return rev;
    }
};

int main() {
    Solution s;
    cout << s.reverse(123) << endl;
}
