class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()

        ans = max(nums[0]*nums[1]*nums[-1] , nums[-1]*nums[-2]*nums[-3])

        return ans