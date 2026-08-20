class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        temp = []
        ans = []

        def solve(i,temp):

            if i==n:
                ans.append(temp.copy())
                return
            
            temp.append(nums[i])

            solve(i+1,temp)

            temp.pop()

            solve(i+1,temp)
        
        solve(0,temp)
        return ans