class Solution:
    def countSubarray(self, arr: list[int], l: int, r: int) -> int:
        # Counts the number of subarrays whose sum is <= k
        def solve(arr, k):
            i = 0          # Left pointer of the sliding window
            curr_sum = 0   # Current window sum
            ans = 0        # Total count of valid subarrays

            # Expand the window by moving the right pointer
            for j in range(len(arr)):
                curr_sum += arr[j]

                # Shrink the window until its sum becomes <= k
                while curr_sum > k:
                    curr_sum -= arr[i]
                    i += 1

                # All subarrays ending at j and starting from i to j are valid
                ans += (j - i + 1)

            return ans

        # Count subarrays with sum in the range [l, r]
        # = Count(sum <= r) - Count(sum <= l - 1)
        return solve(arr, r) - solve(arr, l - 1)