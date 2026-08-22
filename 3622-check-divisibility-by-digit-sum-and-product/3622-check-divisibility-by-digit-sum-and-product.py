class Solution:
    def checkDivisibility(self, n: int) -> bool:
        def digisumprod(n):
            sum = 0
            prod = 1

            while n > 0:
                digi = n % 10
                sum += digi
                prod *= digi
                n //= 10
            
            return sum+prod
        

        return n%digisumprod(n)==0
