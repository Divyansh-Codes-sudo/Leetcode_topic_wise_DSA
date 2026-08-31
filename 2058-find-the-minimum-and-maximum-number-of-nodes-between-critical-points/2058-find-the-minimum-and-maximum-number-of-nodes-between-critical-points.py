# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        arr = []

        temp = head

        while temp:
            arr.append(temp.val)
            temp = temp.next
        
        i = 1
        n = len(arr)
        crit = []
        while i < n-1:
            if (arr[i]<arr[i+1] and arr[i]<arr[i-1]) or (arr[i]>arr[i+1] and arr[i]>arr[i-1]):
                crit.append(i)
                i+=1
            else:
                i+=1
        
        ans = []

        if len(crit) <= 1:
            return [-1 , -1]
        
        mini = float('inf')
        for i in range(1 , len(crit)):
            mini = min(mini , crit[i] - crit[i-1])
        
        return [mini , crit[-1] - crit[0]]
