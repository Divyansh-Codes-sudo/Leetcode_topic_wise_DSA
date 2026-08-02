class Solution {
  public:
  
    int dp[12][12];
    int N,M;
    
    int solve(int idx , int prev){
        if (idx == N) return 1;
        
        if (dp[idx][prev] != -1) return dp[idx][prev];
        
        int ans = 0;
        for (int next = 1 ; next <= M ; next++){
            if (next%prev == 0 || prev%next == 0){
                ans += solve(idx+1 , next);
            }
        }
        
        return dp[idx][prev] = ans;
    }
  
    int count(int n, int m) {
        // code here
        memset(dp , -1 , sizeof(dp));
        N = n;
        M = m;
        
        int ans = 0;
        for (int i = 1 ; i <= m ; i++){
            ans += solve(1 , i);
        }
        
        return ans;
        
    }
};