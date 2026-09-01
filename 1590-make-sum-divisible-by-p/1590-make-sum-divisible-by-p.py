from collections import defaultdict
class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        if sum(nums)%p==0 : return 0
        n = len(nums)

        s = sum(nums)
        target = s%p

        mp = defaultdict(int)

        mp[0] = -1

        cur = 0
        ans = n

        for i in range(n):
            cur = (cur + nums[i]) % p

            needed = (cur - target) % p

            if needed in mp:
                ans = min(ans, i - mp[needed])

            mp[cur] = i

        return ans if ans < n else -1
        