class Solution {
public:
    // Returns the product of digits of a number.
    // If the number is a single digit, return it directly.
    int prod(int n) {
        if (n <= 9) {
            return n;
        }

        int prod = 1;
        while (n != 0) {
            prod *= (n % 10);
            n /= 10;
        }

        return prod;
    }
    int smallestNumber(int n, int t) {
        // If t is already greater than or equal to n,
        // it is the smallest possible answer.
        if (t >= n) return t;
        int i = n;
        // Keep checking consecutive numbers until
        // the product of its digits is divisible by t.
        while (prod(i) % t != 0) {
            i++;
        }
        return i;
    }
};