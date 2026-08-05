class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invo) {
        // Adjacency list representing method invocations
        vector<vector<int>> adj(n);

        // Store indegree of each method
        vector<int> indegree(n, 0);

        // Marks whether a method is suspicious (reachable from k)
        vector<bool> sus(n, false);

        // Build the graph and compute indegrees
        for (auto &vec : invo) {
            adj[vec[0]].push_back(vec[1]);
            indegree[vec[1]]++;
        }

        // BFS to mark all suspicious methods
        queue<int> q;
        q.push(k);
        sus[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                // Remove incoming edge from another suspicious method
                indegree[v]--;

                // Visit each suspicious method only once
                if (!sus[v]) {
                    sus[v] = true;
                    q.push(v);
                }
            }
        }

        vector<int> ans;

        // Verify whether suspicious methods can be removed
        for (int i = 0; i < n; i++) {
            if (sus[i]) {
                // If a suspicious method still has an incoming edge
                // from a non-suspicious method, removal is impossible.
                if (indegree[i] != 0) {
                    ans.resize(n);
                    for (int j = 0; j < n; j++)
                        ans[j] = j;
                    return ans;
                }
            } else {
                // Keep all non-suspicious methods
                ans.push_back(i);
            }
        }

        return ans;
    }
};