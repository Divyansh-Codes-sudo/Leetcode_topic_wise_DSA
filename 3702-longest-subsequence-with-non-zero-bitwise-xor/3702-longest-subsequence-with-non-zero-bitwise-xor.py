class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        resxor = 0
        n = len(nums)
        allzero = True

        for x in nums:
            resxor ^= x

            if x != 0: allzero=False #at least one zero found 
        
        if allzero: return 0

        return n if resxor!=0 else n-1