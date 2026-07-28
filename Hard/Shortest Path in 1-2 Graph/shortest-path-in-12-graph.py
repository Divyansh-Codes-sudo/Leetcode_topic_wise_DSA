from collections import deque
class Solution:
    def shortestPath(self, V: int, src: int, dest: int, edges: list[list[int]]) -> int:
        # code here
        adj = [[] for _ in range(V+len(edges))]
        
        vis = [False] * (V+len(edges))
        newnode = V
        for u,v,w in edges:
            if w==1:
                adj[u].append(v)
                adj[v].append(u)
            else:
                adj[u].append(newnode)
                adj[newnode].append(u)
                
                adj[v].append(newnode)
                adj[newnode].append(v)
                
                newnode+=1
        
        q = deque()
        q.append(src)
        dist = 0
        
        while(len(q) != 0):
            s = len(q)
            
            while(s > 0):
                s-=1
                cur = q.popleft()
                
                if cur==dest:
                    return dist
                
                for v in adj[cur]:
                    if not vis[v]:
                        vis[v] = True
                        q.append(v)
                
            dist+=1
        
        return -1
          
        