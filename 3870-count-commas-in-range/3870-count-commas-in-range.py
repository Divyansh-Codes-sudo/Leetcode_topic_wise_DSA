import math
class Solution:
    def countCommas(self, n: int) -> int:
        if n<1000 : return 0

        ans = 0
        for i in range(1000 , n+1):
            digi = math.floor(math.log10(abs(i))) + 1
            coma = (digi-1) // 3
            ans += coma
        return ans
