from functools import cache
class Solution:
    def findWays(self, grid):
        # code here
        n = len(grid)
        maxadv = 0
        paths = 0
        MOD = (10**9) + 7
        @cache
        def solve(r , c):
            
            
            if r == n-1 and c==n-1:
                return (1 , grid[r][c])
            
            paths = 0
            maxadv = 0
            
            if grid[r][c] == 1 or grid[r][c] == 3:
                if c+1 < n:
                    p , adv = solve(r , c+1)
                
                    paths += p
                    maxadv = max(maxadv , adv)
            
            if grid[r][c] == 2 or grid[r][c] == 3:
                if r+1 < n:
                    p , adv = solve(r+1 , c)
                
                    paths += p
                    maxadv = max(maxadv , adv)
                    
            if paths == 0:
                return (0, 0)
            
            maxadv += grid[r][c]
            return (paths%MOD , maxadv)
        
        return list(solve(0 , 0 ))
        
            
            
            
            