from collections import defaultdict
class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        maxfreq = 0

        freq = defaultdict(int)
        ans = 0
        i , j = 0 , 0

        while( j < len(s)):
            freq[s[j]] += 1

            while (freq[s[j]] > 2):
                freq[s[i]] -= 1
                i+=1
            
            ans = max(ans , j-i+1)

            j+=1
        
        return ans
            

        
