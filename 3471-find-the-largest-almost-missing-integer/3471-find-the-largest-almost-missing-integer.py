from collections import Counter


class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)

        if k == n:
            return max(nums)

        freq = Counter(nums)

        res = -1

        if k == 1 and len(freq) > 1:
            for i in freq:
                if freq[i] == 1:
                    res = max(res, i)

            return res

        if freq[nums[0]] == 1:
            res = max(res, nums[0])

        if freq[nums[-1]] == 1:
            res = max(res, nums[-1])

        return res
