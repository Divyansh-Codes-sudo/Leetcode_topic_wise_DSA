class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        result = [0] * (m + n)
        i = 0
        j = 0
        k = 0
        while i < m and j < n:
            if nums1[i] < nums2[j]:
                result[k] = nums1[i]
                i += 1
                k += 1
            else:
                result[k] = nums2[j]
                k += 1
                j += 1
        while i < m:
            result[k] = nums1[i]
            i += 1
            k += 1

        while j < n:
            result[k] = nums2[j]
            j += 1
            k += 1

        klen = len(result)
        if klen % 2 == 0:
            median = (result[klen // 2] + result[(klen // 2) - 1]) / 2
        else:
            median = result[klen // 2]

        return median
