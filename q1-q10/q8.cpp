#include <string>
#include <iostream>
#include <limits.h>
#include <sstream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        char c;
        bool negative = false;
        long long sum = 0;
        for (; index < s.size(); ++index) {
            c = s[index];
            if (c != ' ') break;
        }
        if (c == '-') negative = true;
        else if (c == '+');
        else if (c > '9' || c < '0') return 0;
        else sum += (c - '0');
        index += 1;
        for (; index < s.size(); ++index){
            c = s[index];
            if (c > '9' || c < '0') {
                break;
            }
            else {
                sum *= 10;
                sum += (c - '0');
            }
            if (sum > INT_MAX){
                if (negative) return INT_MIN;
                else return INT_MAX;
            }
        }
        if (negative) return -sum;
        else return sum;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("+1") << endl;
}
