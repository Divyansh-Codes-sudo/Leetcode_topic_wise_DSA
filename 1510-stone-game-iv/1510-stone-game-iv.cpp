class Solution {
public:

    vector<int> dp;

    bool winnerSquareGame(int n) {
        dp.resize(n+1 , -1);

        return solve(n);
    }

    bool solve(int rem){
        if (rem == 0) return false;

        if (dp[rem] != -1) return dp[rem];

        int x = sqrt(rem);
        for (int i = 1 ; i <= x ; i++){
            if (!solve(rem - (i*i))) return dp[rem] = true;
        }
        return dp[rem] = false;
    }

};