class Solution:

    def countTriplets(self, arr: list[int], l: int, r: int) -> int:
        # code here
        arr.sort()
        n = len(arr)
        res = 0
        res2 = 0
        for i in range(n - 2):
            sum = 0

            s = i + 1
            e = n - 1

            while s<e:
                sum = arr[s] + arr[e] + arr[i]
                if sum <= r:
                    res += e - s
                    s += 1
                else:
                    e -= 1

        for i in range(n - 2):
            sum = 0
            s = i + 1
            e = n - 1
            while s<e:
                sum = arr[s] + arr[e] + arr[i]
                if sum<l:
                    res2 += e - s
                    s += 1
                else:
                    e -= 1

        return res - res2
