class Solution:
    def maxTask(self, h: list[int], l: list[int]) -> int:
        # code here
        n = len(h)
        dp = [[-1 for _ in range(2)] for _ in range(n)]
        
        def solve(index , prevtask):
            if index == n:
                return 0
                
            state = 1 if prevtask else 0
            
            if dp[index][state] != -1: return dp[index][state]
            
            # Eat 5 star
            nothing = solve(index+1 , False)
            
            # Do low effort
            low = l[index] + solve(index+1 , True)
            
            #Do full high effort
            
            high = 0
            if not prevtask:
                high = h[index] + solve(index+1 , True)
            
            dp[index][state] = max([nothing , low , high])
            
            return dp[index][state]
        
        return solve(0 , False)
            
            