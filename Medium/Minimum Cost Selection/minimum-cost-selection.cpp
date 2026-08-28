class Solution {
  public:
    int minCost(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int c0 = mat[0][0];
        int c1 = mat[0][1];
        int c2 = mat[0][2];
        
        for (int i = 1 ; i < n ; i++){
            int t0 = mat[i][0] + min(c1 , c2);
            int t1 = mat[i][1] + min(c0 , c2);
            int t2 = mat[i][2] + min(c1 , c0);
            
            c0 = t0;
            c1 = t1;
            c2 = t2;
        }
        
        return min({c0 , c1 , c2});
    }
};