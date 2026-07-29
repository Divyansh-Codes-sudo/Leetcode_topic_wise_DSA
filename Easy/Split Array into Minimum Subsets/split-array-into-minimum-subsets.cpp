class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        sort(begin(arr) , end(arr));
        int count = 1;
        for(int i = 1 ; i < arr.size() ; i++){
            if (arr[i] - arr[i-1] != 1){
                count++;
            }
        }
        
        return count;
        
    }
};
