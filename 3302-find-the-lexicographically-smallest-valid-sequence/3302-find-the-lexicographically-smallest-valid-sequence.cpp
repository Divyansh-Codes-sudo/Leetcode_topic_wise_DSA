class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j] stores the earliest? 
        // Actually, it stores the position of the character word2[j]
        // while matching word2 from right to left.
        vector<int> last(m, -1);

        int j = m - 1;

        // Find positions to match the suffix of word2.
        for (int i = n - 1; i >= 0; i--) {

            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }

            // Entire word2 has been matched.
            if (j < 0)
                break;
        }

        vector<int> res;
        j = 0;

        // We can modify at most one character.
        bool change = false;

        for (int i = 0; i < n; i++) {

            // All characters of word2 are already selected.
            if (j == m)
                break;

            // Normal matching character.
            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            }

            // Use this index as the one character that we modify.
            //
            // We can modify it if:
            // 1. It is the last character of word2, OR
            // 2. The remaining suffix word2[j+1...] can still
            //    be matched after index i.
            else if (!change && (j == m - 1 || last[j + 1] > i)) {
                res.push_back(i);
                j++;
                change = true;
            }
        }

        // Return the indices only if we successfully selected
        // exactly m characters.
        return res.size() == m ? res : vector<int>{};
    }
};