class Solution:
    def isBipartite(self, V, edges):
        
        # DFS function to color the graph.
        # curr       -> Current vertex being visited.
        # currcolor  -> Color to assign to the current vertex (0 or 1).
        # color      -> Stores the assigned color of every vertex.
        # adj        -> Adjacency list representation of the graph.
        def dfs(curr, currcolor, color, adj):

            # Assign the current color to the vertex.
            color[curr] = currcolor

            # Traverse all neighboring vertices.
            for v in adj[curr]:

                # If the neighbor already has the same color,
                # the graph cannot be bipartite.
                if color[v] == currcolor:
                    return False

                # If the neighbor has not been colored yet,
                # recursively color it with the opposite color.
                if color[v] == -1:

                    # If a conflict is found in any recursive call,
                    # immediately return False.
                    if not dfs(v, 1 - currcolor, color, adj):
                        return False

            # No coloring conflict was found in this DFS traversal.
            return True

        # color[i] stores the color assigned to vertex i.
        # -1 indicates that the vertex has not been visited yet.
        color = [-1] * V

        # Create an adjacency list for the graph.
        adj = [[] for _ in range(V)]

        # Convert the given edge list into an adjacency list.
        # Since the graph is undirected, add edges in both directions.
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        # The graph may have multiple disconnected components.
        # Start DFS from every unvisited vertex.
        for i in range(V):

            # If the current vertex is unvisited,
            # start a DFS with color 0.
            if color[i] == -1:

                # If this connected component cannot be colored
                # using two colors, the graph is not bipartite.
                if not dfs(i, 0, color, adj):
                    return False

        # Every connected component was successfully colored
        # using only two colors, so the graph is bipartite.
        return True