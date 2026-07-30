class Solution:
    def isAlienSorted(self, word: List[str], o: str) -> bool:
        # Store the position of every character in the alien alphabet
        order = {c: i for i, c in enumerate(o)}

        # Compare every adjacent pair of words
        for i in range(len(word) - 1):
            w1 = word[i]
            w2 = word[i + 1]

            # Compare characters one by one
            for j in range(len(w1)):

                # If the second word ends first, then
                # w1 is a prefix extension of w2 (e.g., "apple", "app")
                # which is invalid in lexicographical order.
                if j == len(w2):
                    return False

                # Found the first different character
                if w1[j] != w2[j]:

                    # If the character in w2 comes before the
                    # character in w1 according to the alien order,
                    # then the words are not sorted.
                    if order[w2[j]] < order[w1[j]]:
                        return False

                    # The first differing character determines the order,
                    # so stop comparing this pair of words.
                    break

        # All adjacent pairs are in the correct order
        return True