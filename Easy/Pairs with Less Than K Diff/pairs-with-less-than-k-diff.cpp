class Solution {
public:
    int countPairs(vector<int> &arr, int k) {
        // Sort the array so that valid pairs become contiguous.
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int i = 0;              // Left pointer of the valid window.
        long long ans = 0;      // Stores the total number of valid pairs.

        // Expand the window using the right pointer.
        for (int j = 0; j < n; j++) {

            // Shrink the window until the difference becomes less than k.
            while (i < j && arr[j] - arr[i] >= k)
                i++;

            // All elements between i and j-1 form valid pairs with arr[j].
            ans += (j - i);
        }

        return ans;
    }
};