from collections import deque
class Solution:
    def isBipartite(self, V, edges):
        # code here
        def bfs(u , color , adj):
            color[u] = 0
            
            q = deque()
            
            q.append([u,0])
            
            while(len(q) != 0):
                u , col = q.popleft()
                
                for v in adj[u]:
                    if color[v] == col:
                        return False
                    
                    if color[v] == -1:
                        q.append([v , 1-col])
                        color[v] = 1-col
                
            return True
        
        
        adj = [ [] for _ in range(V)]
        
        color = [-1] * V
        
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        for i in range(V):
            if color[i] == -1:
                if not bfs(i , color , adj):
                    return False
        
        return True