class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        vector<int> nums = {s};
        
        int total = s;
        
        for (int val : arr){
            int next = total + val;
            
            if (next <= x){
                nums.push_back(next);
            }
            
            total += next;
            
            if (total > x && next > x) break;
        }
        
        for (int i = nums.size() - 1 ; i >= 0 ; i--){
            if (nums[i] <= x){
                x -= nums[i];
            }
            
            if (x == 0) return true;
        }
        
        return false;
        
    }
};