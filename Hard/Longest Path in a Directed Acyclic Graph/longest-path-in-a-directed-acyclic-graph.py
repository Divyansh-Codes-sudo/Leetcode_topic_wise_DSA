class Solution:
    def maxDistance(self, V, src, edges):
        # code here
        adj = [[] for _ in range(V)]
        st = []
        for u,v,w in edges:
            adj[u].append([v , -1*w])
        
        dist = [float('INF')] * V
        
        dist[src] = 0
        
        vis = [0]*V
        
        
        def dfs(node):
            vis[node] = 1
            
            for i in adj[node]:
                v = i[0]
                if not vis[v]:
                    dfs(v)
            
            st.append(node)
            
            
        for i in range(V):
            if not vis[i]:
                dfs(i)
        
        
        while (len(st) > 0):
            cur = st.pop()
            
            for v,w in adj[cur]:
                if dist[cur]+w < dist[v]:
                    dist[v] = dist[cur] + w
        
        for i in range(V):
            if dist[i] != float('INF'):
                dist[i] *= -1
            else:
                dist[i] = (-2**31)
        
        return dist
        
        
            

