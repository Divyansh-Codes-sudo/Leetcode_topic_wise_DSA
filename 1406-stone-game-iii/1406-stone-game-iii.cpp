class Solution {
public:
    // dp[i] stores the maximum score difference (current player - opponent)
    // starting from index i.
    vector<int> dp;

    int solve(int i, int j, vector<int>& nums) {

        // If no stones are left, the score difference is 0.
        if (i >= j)
            return 0;

        // Return the already computed result.
        if (dp[i] != INT_MIN)
            return dp[i];

        // Option 1: Take only the current stone.
        dp[i] = nums[i] - solve(i + 1, j, nums);

        // Option 2: Take the current and the next stone (if possible).
        if (i + 1 < j) {
            dp[i] = max(dp[i], nums[i] + nums[i + 1] - solve(i + 2, j, nums));
        }

        // Option 3: Take the current and the next two stones (if possible).
        if (i + 2 < j) {
            dp[i] = max(dp[i], nums[i] + nums[i + 1] + nums[i + 2] -
                                   solve(i + 3, j, nums));
        }

        // Store and return the best achievable score difference.
        return dp[i];
    }

    string stoneGameIII(vector<int>& nums) {

        // Initialize DP with INT_MIN to indicate uncomputed states.
        dp.resize(nums.size(), INT_MIN);

        // Compute the maximum score difference starting from index 0.
        int ans = solve(0, nums.size(), nums);

        // Determine the winner based on the final score difference.
        if (ans > 0)
            return "Alice";
        if (ans == 0)
            return "Tie";
        return "Bob";
    }
};