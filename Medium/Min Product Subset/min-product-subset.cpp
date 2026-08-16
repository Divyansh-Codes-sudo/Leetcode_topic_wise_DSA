class Solution {
  public:
  
    int n;
  
    int solve(int ind , int prod , bool taken ,vector<int>& arr){
        if (ind == n){
            if (!taken) return INT_MAX;
            return prod;
        }
        
        int take = solve(ind+1 , prod * arr[ind] , true , arr);
        
        int leave = solve(ind+1 , prod , taken , arr);
        
        return min(take , leave);
        
    }
  
    int minProd(vector<int>& arr) {
        // code here
        n = arr.size();
        return solve(0 , 1 , false , arr);
        
    }
};