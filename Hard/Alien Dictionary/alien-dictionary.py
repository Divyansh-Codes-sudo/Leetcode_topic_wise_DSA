from collections import deque, defaultdict

class Solution:
    def findOrder(self, words):
        # Stores all unique characters present in the dictionary
        mp = defaultdict(int)

        # Adjacency list representing character precedence
        adj = defaultdict(list)

        # Stores the indegree of each character
        indegree = defaultdict(int)

        # Collect all unique characters
        for word in words:
            for ch in word:
                mp[ch] = 0

        # Build the graph by comparing adjacent words
        for i in range(len(words) - 1):
            w1 = words[i]
            w2 = words[i + 1]

            for j in range(len(w1)):

                # Invalid case:
                # If w2 is a prefix of w1, then ordering is impossible
                if j >= len(w2):
                    return ""

                # Ensure both characters are present in the map

                # First differing characters determine the ordering
                if w1[j] != w2[j]:
                    adj[w1[j]].append(w2[j])
                    indegree[w2[j]] += 1
                    break

        # Initialize queue with characters having zero indegree
        q = deque()
        ans = []

        for ch in mp:
            if ch not in indegree:
                q.append(ch)

        # Perform Kahn's Topological Sort
        while len(q) != 0:
            cur = q.popleft()
            ans.append(cur)

            # Reduce indegree of neighboring characters
            for v in adj[cur]:
                indegree[v] -= 1

                # Add to queue once indegree becomes zero
                if indegree[v] == 0:
                    q.append(v)

        # If not all characters are processed,
        # a cycle exists in the graph
        if len(ans) != len(mp):
            return ""

        # Return one valid character ordering
        return ans