from collections import deque

class Solution:
    def isBipartite(self, V, edges):
        # Function to check whether the given graph is bipartite.

        # BFS function to check one connected component
        def bfs(u, color, adj):

            # Assign the starting node color 0
            color[u] = 0

            # Queue stores [node, color]
            q = deque()

            # Push the starting node into the queue
            q.append([u, 0])

            # Continue BFS until the queue becomes empty
            while len(q) != 0:

                # Remove the front node and its color
                u, col = q.popleft()

                # Traverse all adjacent vertices
                for v in adj[u]:

                    # If adjacent vertex has the same color,
                    # the graph is not bipartite
                    if color[v] == col:
                        return False

                    # If the vertex is not colored yet
                    if color[v] == -1:

                        # Assign the opposite color
                        color[v] = 1 - col

                        # Push it into the queue
                        q.append([v, 1 - col])

            # No conflict found in this component
            return True

        # Create an adjacency list
        adj = [[] for _ in range(V)]

        # Initially, every vertex is uncolored (-1)
        color = [-1] * V

        # Build the undirected graph
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        # Check every connected component
        for i in range(V):

            # If the vertex is unvisited
            if color[i] == -1:

                # Perform BFS
                if not bfs(i, color, adj):
                    return False

        # All components satisfy bipartite conditions
        return True