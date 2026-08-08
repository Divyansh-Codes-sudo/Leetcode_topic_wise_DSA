class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n > 0) {
            // Check if the last bit is 1
            if (n & 1)
                count++;

            // Remove the last bit
            n >>= 1;
        }

        return count;
    }
};