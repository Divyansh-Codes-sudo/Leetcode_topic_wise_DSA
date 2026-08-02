class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        # Number of piles
        n = len(piles)

        # dp[i][j] stores the maximum score difference
        # (current player's score - opponent's score)
        # that can be achieved from subarray piles[i...j]
        dp = [[-1 for _ in range(n)] for _ in range(n)]

        def solve(i, j):
            # No piles left
            if i > j:
                return 0

            # Only one pile left, current player takes it
            if i == j:
                return piles[i]

            # Return already computed result
            if dp[i][j] != -1:
                return dp[i][j]

            # Pick the left pile.
            # Opponent will then play optimally, so subtract their best result.
            takei = piles[i] - solve(i + 1, j)

            # Pick the right pile.
            # Opponent will then play optimally.
            takej = piles[j] - solve(i, j - 1)

            # Store the better of the two choices
            dp[i][j] = max(takei, takej)

            return dp[i][j]

        # If the maximum score difference is positive,
        # the first player (Alice) wins.
        return solve(0, n - 1) > 0