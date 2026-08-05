class Solution {
	public:
	
	// Counts the number of subarrays whose sum is <= k
	int solve(vector<int>& arr, int k) {
		// No valid subarray if k is negative
		if (k < 0)
			return 0;
		
		int i = 0; // Left pointer of sliding window
		long long sum = 0; // Current window sum
		long long ans = 0; // Total count of valid subarrays
		
		// Expand the window by moving the right pointer
		for (int j = 0; j < arr.size(); j++) {
			sum += arr[j];
			
			// Shrink the window until its sum becomes <= k
			while (sum > k) {
				sum -= arr[i];
				i++;
			}
			
			// All subarrays ending at j and starting from i to j are valid
			ans += (j - i + 1);
		}
		
		return ans;
	}
	
	int countSubarray(vector<int>& arr, int l, int r) {
		// Count subarrays with sum in [l, r]
		// = Count(sum <= r) - Count(sum <= l-1)
		return solve(arr, r) - solve(arr, l - 1);
	}
};
