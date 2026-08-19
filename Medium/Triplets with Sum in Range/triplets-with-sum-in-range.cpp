class Solution {
  public:
  int countTriplets(vector<int> &arr, int l, int r) {
        sort(begin(arr), end(arr));
        int n = arr.size();
        int res = 0 , res2 = 0;
        for (int i = 0 ; i < n-1 ; i++){
            int s = i+1;
            int e = n-1;
            
            while (s < e){
                int sum = arr[i]+arr[s]+arr[e];
                
                if (sum <= r){
                    res += e-s;
                    s++;
                }else e--;
            }
        }
        for (int i = 0 ; i < n-1 ; i++){
            int s = i+1;
            int e = n-1;
            
            while (s < e){
                int sum = arr[i]+arr[s]+arr[e];
                if (sum < l){
                    res2 += e-s;
                    s++;
                }else e--;
            }
        }
        return res-res2;
    }
};