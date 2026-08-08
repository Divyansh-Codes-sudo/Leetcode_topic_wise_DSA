from collections import deque

class Solution:
    def minEdgesReq(self, V, edges):
        
        # To connect V vertices, we need at least V - 1 edges.
        if len(edges) < V - 1:
            return -1

        # Build adjacency list.
        adj = [[] for _ in range(V)]
        vis = [False] * V

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        extraedges = 0
        components = 0

        # Find one connected component using BFS.
        def bfs(node):
            vis[node] = True

            q = deque([node])

            nonlocal edges
            nonlocal vertices

            while q:

                u = q.popleft()

                # Each undirected edge is counted twice.
                edges += len(adj[u])

                # Count vertices in this component.
                vertices += 1

                for v in adj[u]:
                    if not vis[v]:
                        vis[v] = True
                        q.append(v)

        # Find all connected components.
        for i in range(V):

            if not vis[i]:

                # Reset counts for the current component.
                edges = 0
                vertices = 0

                components += 1

                bfs(i)

                # Every undirected edge was counted twice.
                actualedges = edges // 2

                # A component with 'vertices' nodes needs
                # vertices - 1 edges to remain connected.
                #
                # Any additional edges are redundant/extra edges.
                extraedges += actualedges - vertices + 1

        # To connect 'components' components,
        # we need components - 1 edges.
        requiredEdges = components - 1

        # If enough redundant edges are available,
        # we can connect all the components.
        return requiredEdges if extraedges >= requiredEdges else -1