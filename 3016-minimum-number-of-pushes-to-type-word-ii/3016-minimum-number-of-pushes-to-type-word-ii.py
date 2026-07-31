class Solution:
    def minimumPushes(self, word: str) -> int:
        # Store the frequency of each lowercase alphabet
        freq = [0] * 26

        res = 0

        # Count the occurrence of every character in the word
        for ch in word:
            freq[ord(ch) - ord('a')] += 1

        # Sort frequencies in descending order so that
        # the most frequent characters require the fewest key presses
        freq.sort(reverse=True)

        # Assign characters to keypad positions
        # First 8 characters  -> 1 press
        # Next 8 characters   -> 2 presses
        # Next 8 characters   -> 3 presses
        # Last 2 characters   -> 4 presses
        for i in range(26):
            f = freq[i]

            # Number of presses required for the current frequency group
            press = (i // 8) + 1

            # Add the contribution of the current character
            res += f * press

        # Return the minimum total number of key presses
        return res