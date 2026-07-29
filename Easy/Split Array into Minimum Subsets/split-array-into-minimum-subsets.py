class Solution:
    def minSubsets(self, arr):
        #code here
        arr.sort()
        count = 1
        for i in range(1 , len(arr)):
            if arr[i] - arr[i-1] != 1:
                count+=1
        
        return count