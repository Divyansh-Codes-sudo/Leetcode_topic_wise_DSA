class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        # Returns the product of the digits of a number.
        def prod(x):
            # Single-digit numbers are their own digit product.
            if x <= 9:
                return x

            product = 1
            while x != 0:
                product *= (x % 10)
                x //= 10

            return product

        # If t is already greater than or equal to n,
        # it is the smallest valid answer.
        if t >= n:
            return t

        i = n

        # Search for the first number whose digit product
        # is divisible by t.
        while prod(i) % t != 0:
            i += 1

        return i