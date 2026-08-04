class Solution:
    def countPairs(self, arr, k):
        # Sort the array so that valid pairs appear in a contiguous window.
        arr.sort()

        i = 0          # Left pointer of the current valid window.
        ans = 0        # Stores the total number of valid pairs.

        # Traverse the array using the right pointer.
        for j in range(len(arr)):

            # Shrink the window until the difference becomes less than k.
            while i < j and arr[j] - arr[i] >= k:
                i += 1

            # Every element between i and j-1 forms a valid pair with arr[j].
            ans += (j - i)

        return ans