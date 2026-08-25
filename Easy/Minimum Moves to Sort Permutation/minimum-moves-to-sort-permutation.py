class Solution:
    def minMoves(self, arr):
        """code here"""
        n = len(arr)
        pos = [0] * (n+1)
        
        for i,val in enumerate(arr):
            pos[val] = i
        
        # print (pos)
        maxlen = 1
        curlen = 1
        
        for i in range(2 , n+1):
            if pos[i] > pos[i-1]:
                curlen+=1
            else:
                curlen = 1
            
            maxlen = max(maxlen , curlen)
        
        return n-maxlen