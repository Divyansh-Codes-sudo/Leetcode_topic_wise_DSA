class Solution:

    def fib(self, n: int) -> int:

        if(n<=1): return n

        dp = [-1 for _ in range(n+1)] 
        
        def f(n):
        
            if n<=1: return n

            if(dp[n] != -1): return dp[n]
            dp[n] = f(n-1) + f(n-2) 
            return dp[n]

        return f(n)