class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:

        # dp[i][j] stores the maximum score difference
        # the current player can achieve over the opponent
        # considering only the subarray nums[i...j]
        dp = [[-1 for _ in range(23)] for _ in range(23)]

        def solve(i, j):

            # No elements left
            if i > j:
                return 0

            # Only one element left, current player takes it
            if i == j:
                return nums[i]

            # Return already computed result
            if dp[i][j] != -1:
                return dp[i][j]

            # Pick the left element.
            # Opponent will then play optimally, so subtract their advantage.
            takei = nums[i] - solve(i + 1, j)

            # Pick the right element.
            takej = nums[j] - solve(i, j - 1)

            # Store the best possible score difference
            dp[i][j] = max(takei, takej)

            return dp[i][j]

        # If the maximum score difference is non-negative,
        # Player 1 can win or at least tie.
        return solve(0, len(nums) - 1) >= 0