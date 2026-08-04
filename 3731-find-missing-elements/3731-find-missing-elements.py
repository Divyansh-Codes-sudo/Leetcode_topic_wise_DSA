class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        # Dictionary to store all the elements present in the array
        mp = {}

        mini = 200
        maxi = 0
        ans = []

        # Find the minimum and maximum element
        # while marking every number as present
        for i in nums:
            mp[i] = 1
            maxi = max(maxi, i)
            mini = min(mini, i)

        # Traverse the range [mini, maxi]
        # Any number not present in the dictionary is missing
        for i in range(mini, maxi + 1):
            if i not in mp:
                ans.append(i)

        return ans