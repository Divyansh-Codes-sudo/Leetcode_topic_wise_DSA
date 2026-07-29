class Solution:
    def minSubsets(self, arr):
        # Sort the array so that consecutive elements
        # are placed next to each other.
        arr.sort()

        # At least one subset is always required.
        count = 1

        # Traverse the sorted array.
        for i in range(1, len(arr)):

            # If the current element is not consecutive
            # to the previous element (difference != 1),
            # start a new subset.
            if arr[i] - arr[i - 1] != 1:
                count += 1

        # Return the minimum number of subsets.
        return count