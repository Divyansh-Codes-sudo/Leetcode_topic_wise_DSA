class Solution {
public:

    void dfs(int node,
             vector<vector<pair<int, int>>> &adj,
             vector<int> &vis,
             stack<int> &st) {

        vis[node] = 1;

        for (auto &it : adj[node]) {

            int v = it.first;

            if (!vis[v]) {
                dfs(v, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {

        vector<vector<pair<int, int>>> adj(V);
        stack<int> st;

        // Build graph with negative weights
        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, -w});
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        vector<int> vis(V, 0);

        // Topological sort
        for (int i = 0; i < V; i++) {

            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        // Shortest path on DAG
        while (!st.empty()) {

            int cur = st.top();
            st.pop();

            // Skip nodes unreachable from src
            if (dist[cur] == INT_MAX)
                continue;

            for (auto &it : adj[cur]) {

                int v = it.first;
                int w = it.second;

                if (dist[cur] + w < dist[v]) {
                    dist[v] = dist[cur] + w;
                }
            }
        }

        // Convert back to maximum distances
        for (int i = 0; i < V; i++) {

            if (dist[i] != INT_MAX) {
                dist[i] *= -1;
            }
            else {
                dist[i] = INT_MIN;
            }
        }

        return dist;
    }
};