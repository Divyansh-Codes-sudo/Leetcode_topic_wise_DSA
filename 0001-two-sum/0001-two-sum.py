class Solution:
    def twoSum(self, nums, target):
        mp = {}

        for i , val in enumerate(nums):
            diff = target-val

            if diff in mp: return [mp[diff] , i]
        
            mp[val] = i
        return []