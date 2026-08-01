class Solution {
public:

    // dp[i][j] stores the maximum score difference
    // the current player can achieve over the opponent
    // considering the subarray nums[i...j]
    int dp[23][23];

    int solve(int i, int j, vector<int> &nums) {

        // No elements left
        if (i > j) return 0;

        // Only one element left, current player takes it
        if (i == j) return nums[i];

        // Return the memoized result
        if (dp[i][j] != -1) return dp[i][j];

        // Pick the left element.
        // Opponent then plays optimally, so subtract their advantage.
        int takei = nums[i] - solve(i + 1, j, nums);

        // Pick the right element.
        int takej = nums[j] - solve(i, j - 1, nums);

        // Store the best possible score difference
        return dp[i][j] = max(takei, takej);
    }

    bool predictTheWinner(vector<int>& nums) {

        // Initialize DP table with -1 (uncomputed)
        memset(dp, -1, sizeof(dp));

        // If the maximum score difference is non-negative,
        // Player 1 can win or at least tie.
        return solve(0, nums.size() - 1, nums) >= 0;
    }
};