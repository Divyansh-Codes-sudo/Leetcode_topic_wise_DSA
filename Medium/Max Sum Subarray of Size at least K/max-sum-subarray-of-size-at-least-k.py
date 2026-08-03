class Solution:
    def maxSumWithK(self, arr, k):
        n = len(arr)

        # maxEnd[i] = Maximum subarray sum ending at index i
        maxEnd = [0] * n
        maxEnd[0] = arr[0]

        # Kadane's Algorithm
        for i in range(1, n):
            maxEnd[i] = max(arr[i], arr[i] + maxEnd[i - 1])

        # Sum of the first window of size k
        windowSum = sum(arr[:k])
        ans = windowSum

        # Slide the window
        for i in range(k, n):
            # Add the new element and remove the leftmost element
            windowSum += arr[i] - arr[i - k]

            # Case 1: Take exactly k elements
            ans = max(ans, windowSum)

            # Case 2: Extend the window using the best subarray
            # ending just before the current window
            ans = max(ans, windowSum + maxEnd[i - k])

        return ans