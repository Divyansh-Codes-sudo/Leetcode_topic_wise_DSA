class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0

        while n > 0:
            # Check whether the last bit is 1
            if (n & 1) == 1:
                count += 1

            # Right shift to process the next bit
            n >>= 1

        return count