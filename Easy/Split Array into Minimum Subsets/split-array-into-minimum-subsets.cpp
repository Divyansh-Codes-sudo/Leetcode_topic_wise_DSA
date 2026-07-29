class Solution {
public:
    int minSubsets(vector<int>& arr) {
        
        // Sort the array so that consecutive numbers
        // appear next to each other.
        sort(begin(arr), end(arr));

        // At least one subset is required.
        int count = 1;

        // Traverse the sorted array.
        for (int i = 1; i < arr.size(); i++) {

            // If the current element is NOT consecutive
            // to the previous element (difference != 1),
            // then it cannot be placed in the same subset.
            // Start a new subset.
            if (arr[i] - arr[i - 1] != 1) {
                count++;
            }
        }

        // Return the minimum number of subsets formed.
        return count;
    }
};