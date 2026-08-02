class Solution:
    def count(self, n: int, m: int) -> int:
        # dp[idx][prev] stores the number of valid sequences
        # starting from position 'idx' when the previous
        # chosen number is 'prev'
        dp = [[-1 for _ in range(12)] for _ in range(12)]

        # If the sequence length is 1, every number from 1 to m
        # forms a valid sequence
        if n == 1:
            return m

        def solve(idx, prev):

            # All positions have been filled successfully
            if idx == n:
                return 1

            # Return the memoized result if already computed
            if dp[idx][prev] != -1:
                return dp[idx][prev]

            ans = 0

            # Try every possible next number
            for i in range(1, m + 1):

                # Adjacent numbers are valid if one divides the other
                if i % prev == 0 or prev % i == 0:
                    ans += solve(idx + 1, i)

            # Store and return the computed result
            dp[idx][prev] = ans
            return ans

        ans = 0

        # Choose every possible first element of the sequence
        for i in range(1, m + 1):
            ans += solve(1, i)

        return ans