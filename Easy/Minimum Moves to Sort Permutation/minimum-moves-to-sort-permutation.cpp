class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int pos[n+1];
        
        for (int i = 0 ; i < n ; i++){
            pos[arr[i]] = i;
        }
        
        int ml = 1;
        int cl = 1;
        
        for (int i = 2 ; i <= n ; i++){
            if (pos[i] > pos[i-1]) cl++;
            else cl = 1;
            
            ml = max(ml , cl);
        }
        
        return n-ml;
    }
};