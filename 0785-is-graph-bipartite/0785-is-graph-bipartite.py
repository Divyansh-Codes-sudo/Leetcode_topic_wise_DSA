class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        def dfs(curr , currcolor , color , adj):
            color[curr] = currcolor

            for v in adj[curr]:
                if color[v] == currcolor:
                    return False
                
                if (color[v] == -1):
                    if (not dfs(v , 1-currcolor , color , adj)):
                        return False
            
            return True
        

        n = len(graph)
        color = [-1] * n

        for i in range(n):
            if(color[i] == -1):
                if(not dfs(i , 0 , color , graph)):
                    return False
        
        return True