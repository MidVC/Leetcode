#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int nlen = needle.length();
        int hlen = haystack.length();
        if (nlen > hlen) return -1;

        // generate nextval vector for KMP algorithm
        vector<int> nextval(nlen);
        int j = 0, k = -1;
        nextval[0] = -1;
        while (j < nlen-1) {
            if (k == -1 || needle[j] == needle[k]) {
                ++j; ++k;
                if (needle[j] != needle[k]) {
                    nextval[j] = k;
                }
                else nextval[j] = nextval[k];
            }
            else {
                k = nextval[k];
            }
        }

        // search for the needle in haystack
        j = 0; k = 0; // j is the pointer to needle, k is the pointer to haystack
        while (j < nlen && k < hlen) {
            if (j == -1 || needle[j] == haystack[k]) {
                ++j; ++k;
            }
            else j = nextval[j];
        }

        // print the result
        if (j >= nlen) return k-nlen;
        return -1;
    }
};

int main() {
    Solution s;
    string a, b;
    cin >> a >> b;
    int i = s.strStr(a, b);
    cout << i << endl;
}
