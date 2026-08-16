class Solution:
    def minProd(self, arr):
        
        n = len(arr)
        
        # code here
        def solve(ind , prod , selected):
            if ind == n:
                if selected:
                    return prod
                return float('inf')
                
            take = solve(ind+1 , prod*arr[ind] , True)
            
            leave = solve(ind+1 , prod , selected)
            
            return min(take , leave)
            
            
            
        return solve(0 , 1 , False)
        