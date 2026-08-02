class Solution {
public:
    // dp[i][j] stores the maximum score difference
    // (current player's score - opponent's score)
    // that can be obtained from piles[i...j]
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& nums) {

        // No piles left
        if (i > j)
            return 0;

        // Only one pile left, current player takes it
        if (i == j)
            return nums[i];

        // Return already computed result
        if (dp[i][j] != -1)
            return dp[i][j];

        // Pick the left pile.
        // Opponent will then play optimally.
        int takei = nums[i] - solve(i + 1, j, nums);

        // Pick the right pile.
        // Opponent will then play optimally.
        int takej = nums[j] - solve(i, j - 1, nums);

        // Store the best possible score difference
        return dp[i][j] = max(takei, takej);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        // Initialize memoization table
        dp.resize(n, vector<int>(n, -1));

        // Alice wins if her score difference is positive
        return solve(0, n - 1, piles) > 0;
    }
};