#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1) return s;

        vector<string> rows(numRows);
        int curRow = 0;
        int dir = -1;
        int slen = s.length();
        for (int i = 0; i < slen; i++) {
            if (curRow == numRows - 1 || curRow == 0) dir *= (-1);
            rows[curRow] += s[i];
            if (dir == 1) curRow++;
            else curRow--;
        }

        string res;
        for (auto &it : rows) res += it;
        return res;

    }
};

int main() {
    Solution s;
    string out = s.convert("PAYPALISHIRING", 3);
    cout << out << endl;
}