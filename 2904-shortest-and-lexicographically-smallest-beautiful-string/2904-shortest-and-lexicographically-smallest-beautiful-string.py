class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        n = len(s)

        ones = 0
        ans = ""
        l  = 0

        for r in range(n):
            if s[r]=='1' : ones+=1

            while l <= r and (ones > k or (ones== k and s[l]=='0')):
                if s[l]=='1' : ones -= 1
                l+=1

            if ones == k:
                sub = s[l : r+1]
                if (not ans or 
                len(sub)<len(ans) or 
                (len(sub)==len(ans) and sub<ans)):
                    ans = sub
        
        return ans




       

        