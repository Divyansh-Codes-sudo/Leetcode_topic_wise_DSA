class Solution {
public:
    int digisumprod(int n) {
        if (n <= 9)
            return 2 * n;

        int sum = 0;
        int prod = 1;

        while (n > 0) {
            int digi = n % 10;
            sum += digi;
            prod *= digi;
            n /= 10;
        }

        return sum + prod;
    }

    bool checkDivisibility(int n) { return n % digisumprod(n) == 0; }
};