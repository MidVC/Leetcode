#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n-1);
        string ans;
        int index = 1;
        char last = s[0];
        int count = 1;
        while (index < s.length()) {
            if (s[index] == last) count++;
            else {
                ans.push_back('0' + count);
                ans.push_back(last);
                last = s[index];
                count = 1;
            }
            index++;
        }
        ans.push_back('0' + count);
        ans.push_back(last);
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay((2)) << endl;
}
