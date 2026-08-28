from collections import Counter
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        mp = Counter(nums)

        for i in range(1 , max(nums)+1):
            if i not in mp:
                return i
        
        x = max(nums)
        
        if x < 0: return 1
        else : return x+1
        

        
