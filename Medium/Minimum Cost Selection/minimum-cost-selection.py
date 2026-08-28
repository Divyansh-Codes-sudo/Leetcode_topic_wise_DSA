class Solution:

    def minCost(self, mat):
        """code here"""
        n = len(mat)
        choice1 = mat[0][0]
        choice2 = mat[0][1]
        choice3 = mat[0][2]
        
        for i in range(1 , n):
            cur1 = mat[i][0] + min(choice2 , choice3)
            cur2 = mat[i][1] + min(choice1 , choice3)
            cur3 = mat[i][2] + min(choice1 , choice2)
            
            choice1 = cur1
            choice2 = cur2
            choice3 = cur3
        
        return min(choice1 , choice2 , choice3)