class Solution:
    def zigzagSequence(self, mat):
        # code here
        n = len(mat)
        dp = [[-1 for _ in range(n)] for _ in range(n)]
        
        def solve(row , col):
            if row==n-1: return mat[row][col]
            
            if dp[row][col] != -1:
                return dp[row][col]
            
            best = 0
            for i in range(n):
                if i != col: best = max(best , solve(row+1 , i))
            
            dp [row] [col] = (mat[row][col] + best)
            return dp[row][col]
        
        
        res = 0
        for i in range(n):
            res = max(res , solve(0 , i))
        
        return res