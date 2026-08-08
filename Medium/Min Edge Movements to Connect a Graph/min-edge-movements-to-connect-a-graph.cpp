class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;

    // BFS to find the number of vertices and edges
    // present in one connected component.
    void bfs(int u, int &vertices, int &edges) {

        queue<int> q;
        q.push(u);
        vis[u] = true;

        while (!q.empty()) {

            int cur = q.front();
            q.pop();

            // Count vertices in this component.
            vertices++;

            // Each undirected edge is counted twice.
            edges += adj[cur].size();

            for (int v : adj[cur]) {

                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    int minEdgesReq(int V, vector<vector<int>>& edges) {

        // To connect V vertices, at least V-1 edges are required.
        if (edges.size() < V - 1)
            return -1;

        // Build adjacency list.
        adj.resize(V);
        vis.assign(V, false);

        int extraedges = 0;
        int components = 0;

        for (auto &vec : edges) {

            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Find all connected components.
        for (int i = 0; i < V; i++) {

            if (!vis[i]) {

                components++;

                int vertices = 0;
                int edgess = 0;

                bfs(i, vertices, edgess);

                // Since the graph is undirected, every edge
                // was counted twice during BFS.
                int actualedges = edgess / 2;

                // A connected component with 'vertices' nodes
                // needs exactly vertices - 1 edges to form a tree.
                //
                // Any edge beyond that is an extra/redundant edge
                // that can potentially be used to connect components.
                extraedges += actualedges - vertices + 1;
            }
        }

        // To connect 'components' components,
        // we need components - 1 edges.
        int required = components - 1;

        // If we have enough redundant edges, we can connect
        // all the components.
        if (extraedges >= required)
            return required;

        return -1;
    }
};