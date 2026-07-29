class Solution {
public:

    // DFS function to color the graph.
    // curr       -> Current node being visited.
    // currcolor  -> Color to assign to the current node (0 or 1).
    // color      -> Stores the assigned color of every node.
    // adj        -> Adjacency list representation of the graph.
    bool dfs(int curr, int currcolor, vector<int> &color, vector<vector<int>> &adj) {

        // Assign the current color to the node.
        color[curr] = currcolor;

        // Visit all adjacent (neighboring) nodes.
        for (int v : adj[curr]) {

            // If the neighbor already has the same color as the
            // current node, the graph cannot be bipartite.
            if (currcolor == color[v])
                return false;

            // If the neighbor has not been colored yet,
            // recursively color it with the opposite color.
            if (color[v] == -1) {

                // If any recursive call detects a conflict,
                // immediately return false.
                if (!dfs(v, 1 - currcolor, color, adj))
                    return false;
            }
        }

        // No coloring conflict was found in this DFS traversal.
        return true;
    }

    bool isBipartite(int V, vector<vector<int>> &edges) {

        // color[i] stores the color assigned to vertex i.
        // -1 means the vertex has not been visited/colored yet.
        vector<int> color(V, -1);

        // Create an adjacency list for the graph.
        vector<vector<int>> adj(V);

        // Convert the edge list into an adjacency list.
        // Since the graph is undirected, add both directions.
        for (auto vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // The graph may have multiple disconnected components,
        // so start DFS from every unvisited vertex.
        for (int i = 0; i < V; i++) {

            // If the current vertex has not been colored,
            // begin a new DFS with color 0.
            if (color[i] == -1) {

                // If this component cannot be colored using
                // two colors, the graph is not bipartite.
                if (!dfs(i, 0, color, adj))
                    return false;
            }
        }

        // Every connected component was successfully colored
        // using only two colors, so the graph is bipartite.
        return true;
    }
};