class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        # dp array for memo
        dp = [[[-1 for _ in range(101)] for _ in range(101)] for _ in range(2)]

        n = len(piles)

        def solve(person, index, m):
            # if index reached so alice no stones left :(
            if index >= n:
                return 0

            # check if common subproblem here
            if dp[person][index][m] != -1:
                return dp[person][index][m]


            #as we compute max for alice and min for BOB
            result = -1 if person == 1 else float("inf")

            stones = 0

            for x in range(1, min(2 * m, n - index) + 1):

                #add current stones 
                stones += piles[index + x - 1]

                if person == 1:  #if Alice
                    result = max(result, stones + solve(0, index + x, max(m, x)))

                else: #if Bob
                    result = min(result, solve(1, index + x, max(m, x)))

            dp[person][index][m] = result #store result in dp
            
            return result

        return solve(1, 0, 1)
