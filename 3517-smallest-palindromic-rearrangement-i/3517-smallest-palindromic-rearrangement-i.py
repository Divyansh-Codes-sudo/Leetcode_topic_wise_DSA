class Solution:
    def smallestPalindrome(self, s: str) -> str:
        
        n = len(s)
        s = list(s)
        mid = n//2
        s[:mid] = sorted(s[:mid])
        for i in range(mid):
            s[n-1-i] = s[i]
        
        return ("".join(s))