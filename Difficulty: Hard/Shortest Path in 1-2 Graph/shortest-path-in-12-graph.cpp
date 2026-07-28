class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        
        // Create adjacency list.
        // Maximum possible nodes = Original vertices + one dummy node per edge.
        vector<vector<int>> adj(V + edges.size());

        // Index of the next dummy node.
        int newnode = V;

        // Build the transformed graph.
        for (auto vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            // If edge weight is 1, keep it unchanged.
            if (w == 1) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            else {
                // Replace every weight-2 edge:
                //
                //      u ----(2)---- v
                //
                // with
                //
                //      u --(1)-- dummy --(1)-- v
                //
                // so that every edge in the new graph has weight 1.

                adj[u].push_back(newnode);
                adj[newnode].push_back(u);

                adj[v].push_back(newnode);
                adj[newnode].push_back(v);

                // Move to the next available dummy node.
                newnode++;
            }
        }

        // Standard BFS.
        queue<int> q;

        // Visited array for all original + dummy nodes.
        vector<bool> vis(newnode, false);

        // Start BFS from the source node.
        q.push(src);
        vis[src] = true;

        // Stores the current BFS level,
        // which is also the shortest distance from src.
        int dist = 0;

        while (!q.empty()) {

            // Number of nodes present in the current level.
            int s = q.size();

            // Process one complete BFS level.
            while (s--) {

                int cur = q.front();
                q.pop();

                // Destination reached.
                // Since BFS explores level by level,
                // the first time we reach the destination
                // is guaranteed to be the shortest distance.
                if (cur == dest)
                    return dist;

                // Visit all unvisited neighbours.
                for (int v : adj[cur]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            // Move to the next BFS level.
            dist++;
        }

        // Destination is unreachable.
        return -1;
    }
};