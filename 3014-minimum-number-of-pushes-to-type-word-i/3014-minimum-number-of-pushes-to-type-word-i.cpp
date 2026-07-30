class Solution {
public:
    int minimumPushes(string word) {
        // Get the length of the given word
        int n = word.size();

        // If the word has fewer than 8 characters,
        // each character can be assigned to a unique key
        // requiring only one push.
        if (n < 8) return n;

        int ans = 0;      // Stores the total number of key presses
        int round = 1;    // Represents the current press count (1st, 2nd, 3rd...)

        // Process characters in groups of 8.
        // Each group of 8 characters requires 'round' presses.
        while (n >= 8) {
            ans += (round * 8); // Add cost for the current group
            n -= 8;             // Remove processed characters
            round++;            // Next group needs one extra press
        }

        // Add the cost for any remaining characters
        ans += (n * round);

        // Return the minimum total key presses
        return ans;
    }
};