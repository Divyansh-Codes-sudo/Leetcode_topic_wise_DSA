class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();

        // maxEnd[i] = maximum subarray sum ending at i
        vector<int> maxEnd(n);

        maxEnd[0] = arr[0];

        for (int i = 1; i < n; i++)
            maxEnd[i] = max(arr[i], arr[i] + maxEnd[i - 1]);

        // First window of size k
        int windowSum = 0;
        for (int i = 0; i < k; i++)
            windowSum += arr[i];

        int ans = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {

            windowSum += arr[i];
            windowSum -= arr[i - k];

            // Exactly k elements
            ans = max(ans, windowSum);

            // More than k elements
            ans = max(ans, windowSum + maxEnd[i - k]);
        }

        return ans;
    }
};