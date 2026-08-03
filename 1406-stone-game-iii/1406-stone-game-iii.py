class Solution:
    def stoneGameIII(self, nums: List[int]) -> str:
        n = len(nums)

        # dp[i] stores the maximum score difference (current player - opponent)
        # starting from index i.
        dp = [-1] * n

        def solve(i):
            # If no stones are left, the score difference is 0.
            if i >= n:
                return 0

            # Return the already computed result.
            if dp[i] != -1:
                return dp[i]

            # Option 1: Take only the current stone.
            dp[i] = nums[i] - solve(i + 1)

            # Option 2: Take the current and the next stone (if possible).
            if i + 1 < n:
                dp[i] = max(
                    dp[i],
                    nums[i] + nums[i + 1] - solve(i + 2)
                )

            # Option 3: Take the current and the next two stones (if possible).
            if i + 2 < n:
                dp[i] = max(
                    dp[i],
                    nums[i] + nums[i + 1] + nums[i + 2] - solve(i + 3)
                )

            # Store and return the best achievable score difference.
            return dp[i]

        # Compute the maximum score difference starting from index 0.
        ans = solve(0)

        # Determine the winner based on the final score difference.
        if ans < 0:
            return "Bob"

        if ans > 0:
            return "Alice"

        return "Tie"