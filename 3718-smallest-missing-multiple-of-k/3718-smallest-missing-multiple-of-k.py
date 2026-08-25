from collections import Counter
class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        mp = Counter(nums)
        n = max(nums)
        i = k
        while i<= n+k:
            if i%k == 0 and i not in mp:
                return i
            i += k
        
