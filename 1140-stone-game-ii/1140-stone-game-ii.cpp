class Solution {
public:
    int n;
    int dp[2][101][101];
    int solve(int person , int index , int m , vector<int> &piles){
        if (index >= n) return 0;

        if (dp[person][index][m] != -1) return dp[person][index][m];

        int result;

        if (person == 1) result = -1;
        else result=INT_MAX;

        int stones = 0;

        for (int x = 1 ; x <= min(2*m , n-index) ; x++){
            
            stones+= piles[index + x - 1];

            if (person == 1){ //Alice
                result = max(result , stones + solve(0 , index+x , max(m , x) , piles));
            }

            else{ //BOB
                result = min(result , solve(1 , index+x , max(m , x) , piles));
            }


        }

        return  dp[person][index][m] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset (dp , -1 , sizeof(dp));
        return solve(1 , 0 , 1 , piles);
    }
};