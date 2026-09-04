class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        premax = [0] * n
        premax[0] = nums[0]
        premin = [0] * n
        premin[-1] = nums[-1]

        for i in range(1,n):
            premax[i] = max(premax[i-1] ,nums[i])
        
        for i in range(n-2 , -1 , -1):
            premin[i] = min(premin[i+1] , nums[i])

        stable = float('inf')

        for i in range(n):
            instablity = premax[i] - premin[i]

            if instablity <= k:
                stable = min(stable , i)
        
        return -1 if stable==float('inf') else stable

