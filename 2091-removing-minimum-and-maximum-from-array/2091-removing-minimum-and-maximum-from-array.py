class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)

        if n<= 2: return n

        maxi = nums.index(max(nums))
        mini = nums.index(min(nums))

        left = min(maxi , mini)
        right = max(maxi , mini)
        # print(maxi , mini)

        return min(left+1+n-right , right+1 , n-left)

        
        

