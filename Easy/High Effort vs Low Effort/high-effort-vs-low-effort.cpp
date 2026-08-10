class Solution {
  public:
  
  int n;
  vector<vector<int>> dp;
  
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        n = h.size();
        dp.resize(n , vector<int>(2 , -1));
        
        return solve(0 , 0 , h , l);
        //0 for false and 1 for true
        
    }
    
    int solve(int index , int prevtask ,vector<int>& h, vector<int>& l){
        if (index == n){
            return 0;
        }
        
        if (dp[index][prevtask] != -1) return dp[index][prevtask];
        
        // Eat 5 Start
        int nothing = solve(index+1 , 0 , h , l);
        
        int low = l[index] + solve(index+1 , 1 , h , l);
        
        int high = 0;
        if (prevtask == 0){
            high = h[index] + solve(index+1 , 1 , h , l);
        }
        
        return dp[index][prevtask] = max({nothing , high , low});
        
    }
    
};