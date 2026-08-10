class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        @cache
        def solve(rem):
            if rem == 0:
                return False

            for i in range(1, int(sqrt(rem)) + 1):
                if not solve(rem - (i**2)):

                    return True

            return False

        return solve(n)
