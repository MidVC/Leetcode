#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashtable;
        for (auto s : strs) {
            string str = s;
            sort(str.begin(), str.end());
            hashtable[str].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto pair: hashtable) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};