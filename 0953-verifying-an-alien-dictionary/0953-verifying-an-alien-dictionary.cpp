class Solution {
public:
    bool isAlienSorted(vector<string>& words, string o) {

        // Store the position of each character in the alien alphabet
        vector<int> order(26);
        for (int i = 0; i < o.size(); i++) {
            order[o[i] - 'a'] = i;
        }

        // Compare every adjacent pair of words
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            // Compare characters one by one
            for (int j = 0; j < w1.size(); j++) {

                // If the second word ends before the first,
                // then w1 is a prefix extension of w2
                // (e.g., "apple" comes before "app"), which is invalid.
                if (j == w2.size())
                    return false;

                // Found the first differing character
                if (w1[j] != w2[j]) {

                    // If the character in w2 appears before the character
                    // in w1 according to the alien alphabet,
                    // then the words are not sorted.
                    if (order[w2[j] - 'a'] < order[w1[j] - 'a'])
                        return false;

                    // The first differing character determines the order,
                    // so stop comparing the current pair of words.
                    break;
                }
            }
        }

        // All adjacent pairs are in the correct alien dictionary order
        return true;
    }
};