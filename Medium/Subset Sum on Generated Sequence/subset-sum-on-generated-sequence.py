class Solution:
    def isPossible(self, arr, s, x):
        # code here 
        finalSeq = [s]
        
        total = s
        
        for i in arr:
            next = total + i
            
            if next<=x:
                finalSeq.append(next)
                
            total += next
            
            if total>x and next>x:
                break
        
        
        for i in range(len(finalSeq)-1 ,-1 , -1):
            if finalSeq[i] <= x:
                x -= finalSeq[i]
            
            if x==0:return True
        
        return False
            
        

        
        