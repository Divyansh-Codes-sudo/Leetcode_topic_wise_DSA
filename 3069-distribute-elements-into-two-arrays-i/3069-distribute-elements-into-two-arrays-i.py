class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        if len(nums) <= 2:
            return nums

        arr1 = [nums[0]]
        arr2 = [nums[1]]

        ind = 2

        while ind < len(nums):
            if arr1[-1] > arr2[-1]:
                arr1.append(nums[ind])
                ind+=1
            else:
                arr2.append(nums[ind])
                ind+=1
        
        res = []

        for i in arr1:
            res.append(i)

        for i in arr2:
            res.append(i)

        return res
