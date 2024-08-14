#include <string>
#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0 || s.length() < t.length()) return "";

        vector<int> map(128, 0);
        int count = t.length();
        // l pointer is the left margin window, s[l] is not included in the window
        int l = -1;
        int r = 0;
        int minLen = INT_MAX;
        int startIndex = -1;

        for (auto c : t) {
            map[c]++;
        }

        // find the right pointer to form a window
        while (r < s.length()) {
            map[s[r]]--;
            if (map[s[r]] >= 0) count--;
            // find the left pointer to make the smallest window
            while (count == 0) {
                // update the window if necessary
                if (r-l < minLen) {
                    minLen = r-l;
                    startIndex = l+1;
                }
                l++;
                map[s[l]]++;
                if (map[s[l]] > 0) count++;
            }
            r++;
        }

        if (startIndex == -1) return "";
        return s.substr(startIndex, minLen);
    }
};

int main() {
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
}
