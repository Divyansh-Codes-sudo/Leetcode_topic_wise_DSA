class Solution {
  public:
  
    // BFS function to check if a connected component is bipartite
    bool bfs(int u, vector<vector<int>> &adj, vector<int> &color) {
        
        // Queue stores {node, color}
        queue<pair<int, int>> q;
        
        // Start BFS from source node with color 0
        q.push({u, 0});
        color[u] = 0;
        
        while (!q.empty()) {
            
            // Get current node and its color
            auto p = q.front();
            int u = p.first;
            int col = p.second;
            q.pop();
            
            // Traverse all neighbours
            for (int v : adj[u]) {
                
                // If neighbour has same color as current node,
                // graph cannot be bipartite
                if (color[v] == col)
                    return false;
                
                // If neighbour is not colored yet
                if (color[v] == -1) {
                    
                    // Assign opposite color
                    color[v] = 1 - col;
                    
                    // Push neighbour into queue
                    q.push({v, 1 - col});
                }
            }
        }
        
        // No conflict found
        return true;
    }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        
        // Initially every vertex is uncolored
        vector<int> color(V, -1);
        
        // Adjacency list
        vector<vector<int>> adj(V);
        
        // Build the graph
        for (auto vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Check every connected component
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bfs(i, adj, color))
                    return false;
            }
        }
        
        return true;
    }
};