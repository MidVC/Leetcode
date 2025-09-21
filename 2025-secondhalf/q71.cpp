#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string ans = "/";
        int curPos = 0;
        while (curPos < path.length()) {
            string nextDir = getNextDir(path, curPos);
            if (nextDir == ".") continue;
            else if (nextDir == "..") {
                if (ans.length() == 1) continue;
                ans = ans.substr(0, getPrevPos(ans));
                if (ans.length() == 0) ans = "/";
            } else if (nextDir == "") break;
            else {
                if (ans.length() == 1) ans.append(nextDir);
                else ans.append("/" + nextDir);
            }
        }
        return ans;
    }
private:
    string getNextDir(string &path, int &pos) {
        while (path[pos] == '/' && pos < path.length()) {pos++;}
        int start = pos;
        while (path[pos] != '/' && pos < path.length()) {pos++;}
        return path.substr(start, pos-start);
    }
    int getPrevPos(string &ans) {
        int end = ans.length() - 1;
        while (ans[end] != '/') {end--;}
        return end;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    string path = "/a/../../b/../c//.//";
    Solution s;
    string ans = s.simplifyPath(path);
    cout << ans << endl;
}