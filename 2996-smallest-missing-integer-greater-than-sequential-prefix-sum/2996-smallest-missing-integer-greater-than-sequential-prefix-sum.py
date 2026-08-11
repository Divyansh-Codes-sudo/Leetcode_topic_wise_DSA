class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        mp = {}

        for num in nums:
            mp[num] = 1
        
        # print(mp)

        presum = nums[0]
        index = 1
        while index < len(nums):
            if nums[index] == nums[index-1]+1:
                presum += nums[index]
                index+=1
            else:
                break
        
        while presum in mp:
            presum += 1
        
        return presum

