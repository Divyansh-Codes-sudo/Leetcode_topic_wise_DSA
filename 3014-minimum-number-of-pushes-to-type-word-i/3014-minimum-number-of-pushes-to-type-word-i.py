class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)

        if n <= 8:
            return n
        
        rounds = 1
        ans = 0

        while(n >= 8):
            ans += rounds*8
            n -= 8
            rounds+=1
        
        ans += rounds*n

        return ans
