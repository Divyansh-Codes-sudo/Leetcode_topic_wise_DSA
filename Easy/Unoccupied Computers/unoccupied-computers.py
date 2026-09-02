class Solution:
    def solve(self, n, s):
        using = set()
        seen = set()
        ans = 0
    
        for c in s:
            if c not in seen:        
                seen.add(c)
    
                if n > 0:
                    n -= 1
                    using.add(c)
                else:
                    ans += 1
    
            else:                      
                if c in using:
                    n += 1
                    using.remove(c)
    
        return ans