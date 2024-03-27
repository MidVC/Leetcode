from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def dfs(left, right, s):
            if len(s) == 2 * n:
                ans.append(s)
                return
            if left < n:
                dfs(left + 1, right, s + '(')
            
            if right < left:
                dfs(left, right + 1, s + ')')

        dfs(0, 0, '')
        return ans
