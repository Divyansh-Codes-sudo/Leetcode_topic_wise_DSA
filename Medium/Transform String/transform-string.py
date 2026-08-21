from collections import Counter
class Solution:
    def transform(self, s1, s2): 
        #code here
        n = len(s1)
        
        if n != len(s2): return -1
        
        mp = Counter(s1)
        for ch in s2:
            if ch not in mp:
                return -1
            
            mp[ch] -= 1
        
        for key in mp:
            if mp[key] != 0: return -1
            
        i = n-1
        j = n-1
        
        while i>=0 and j>=0:
            if s1[i] == s2[j]:
                i-=1
                j-=1
            else:
                i-=1
        
        return j+1