class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int dec = 0;
        
        int maxdivide = 0;
        
        for (int num : arr){
            int divide = 0;
            
            while (num > 0){
                if (num % 2 == 1){
                    dec++;
                    num--;
                }else{
                    divide++;
                    num = num/2;
                }
            }
            
            maxdivide = max(divide , maxdivide);
            
        }
        
        return maxdivide+dec;
        
    }
};