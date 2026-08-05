from collections import deque


class Solution:
    def remainingMethods(
        self, n: int, k: int, invocations: List[List[int]]
    ) -> List[int]:
        indegree = [0] * n

        suspicious = [False] * n

        adj = [[] for _ in range(n)]

        for u, v in invocations:
            adj[u].append(v)
            indegree[v] += 1

        q = deque()

        q.append(k)

        suspicious[k] = True

        while len(q) != 0:
            cur = q.popleft()

            for v in adj[cur]:
                indegree[v] -= 1
                if (not suspicious[v]):
                    suspicious[v] = True
                    q.append(v)

        ans = []
        for i in range(n):
            if suspicious[i] == True:
                if indegree[i] != 0:
                    return list(i for i in range(n))
            else:
                ans.append(i)

        return ans
