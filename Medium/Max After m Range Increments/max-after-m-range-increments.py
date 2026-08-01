class Solution:
    def findMax(self, n, a, b, k):
        # Difference array to efficiently perform range updates
        diff = [0] * n

        # Apply all range increment operations
        for i in range(len(a)):
            # Start of the range
            diff[a[i]] += k[i]

            # End of the range (exclusive)
            if b[i] + 1 < n:
                diff[b[i] + 1] -= k[i]

        curr = 0
        ans = 0

        # Compute the prefix sum to reconstruct the final array
        # and simultaneously track the maximum value
        for x in diff:
            curr += x
            ans = max(ans, curr)

        return ans