#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:

    const vector<string> ref = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> ans;
        ans.push_back("");

        for (auto digit: digits) {
            vector<string> temp;
            for (auto c: ref[digit - '0']) {
                for (auto s: ans) {
                    temp.push_back(s + c);
                }
            }
            ans.swap(temp);
        }
        
        return ans;
    }
};
