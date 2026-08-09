class Solution {
  public:
  
    int n;
    int dp[101][101];
    
    int solve(int row , int col , vector<vector<int>>& mat){
        if (row == n-1) return mat[row][col];
        
        if (dp[row][col] != -1) return dp[row][col];
        
        int best = 0;
        
        for (int i = 0 ; i < n ; i++){
            if (i != col){
                best = max(best , solve(row+1 , i , mat));
            }
        }
        
        return dp[row][col] = (best + mat[row][col]);
        
    }
  
    int zigzagSequence(vector<vector<int>>& mat) {
        // code here
        n = mat.size();
        
        memset(dp , -1 , sizeof(dp));
        
        int res = 0;
        for (int i = 0 ; i < n ; i++){
            res = max(res , solve(0 , i , mat));
        }
        
        return res;
        
    }
};