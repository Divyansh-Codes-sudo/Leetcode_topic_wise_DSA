class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        sum = 0
        n = len(nums)

        for i in range(n):
            distelem = set()

            for j in range(i , n):

                distelem.add(nums[j])

                sum += (len(distelem) ** 2)
        
        return sum