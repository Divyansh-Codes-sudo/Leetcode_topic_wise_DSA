# Recursive Solution
# Time Complexity: O(2^n)
# Space Complexity: O(n) (recursion stack)

class Solution:
    def countFriendsPairings(self, n: int) -> int:
        # Base cases:
        # If there is 1 friend, only 1 way (single).
        # If there are 2 friends, either both stay single or they pair up.
        if n <= 2:
            return n

        # Case 1: nth friend stays single.
        # Remaining (n-1) friends can be paired in f(n-1) ways.
        single = self.countFriendsPairings(n - 1)

        # Case 2: nth friend pairs with one of the (n-1) friends.
        # Choose one friend in (n-1) ways, then pair the remaining (n-2) friends.
        paired = (n - 1) * self.countFriendsPairings(n - 2)

        # Total ways = single + paired
        return single + paired