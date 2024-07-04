#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> pstack;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || pstack.empty()) {
                pstack.push(i);
            }
            else {
                if (s[pstack.top()] == '(') {
                    pstack.pop();
                }
                else pstack.push(i);
            }
        }

        if (pstack.empty()) return s.length();

        int previous = s.length();
        int longest = 0;

        while (!pstack.empty()) {
            if (longest < previous - pstack.top() - 1) longest = previous - pstack.top() - 1;
            previous = pstack.top();
            pstack.pop();
        }
        if (longest < previous) longest = previous;
        return longest;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses("") << endl;
    return 0;
}
