#include <string>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int last = s.size(), first = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] != ' ') {
                last = i;
                break;
            }
        }
        for (int i = last - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                first = i + 1;
                break;
            }
        }
        return last - first + 1;
    }
};