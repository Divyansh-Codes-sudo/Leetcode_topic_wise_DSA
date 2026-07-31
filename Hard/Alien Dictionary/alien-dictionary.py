from collections import deque , defaultdict
class Solution:
    def findOrder(self, words):
        # code here
        # code here
        mp = defaultdict(int)
        adj = defaultdict(list)
        indegree = defaultdict(int)
        
        for word in words:
            for ch in word:
                mp[ch] = 0
        
        for i in range(len(words) - 1):
            w1 = words[i]
            w2 = words[i+1]
            for j in range(len(w1)):
                
                if j>=len(w2):
                    return ""
                
                if w1[j] not in mp:
                    mp[w1[j]] = 0
                    
                if w2[j] not in mp:
                    mp[w2[j]] = 0
                
                if w1[j] != w2[j]:
                    adj[w1[j]].append(w2[j])
                    indegree[w2[j]] += 1
                    break

        # print(adj)
        
        q = deque()
        ans = []
        
        for i in mp:
            if i not in indegree:
                q.append(i)

        # print(indegree)
        # print(q)
        
        while(len(q) != 0):
            cur = q.popleft()
            ans.append(cur)
            
            for v in adj[cur]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    q.append(v)
        
        if len(ans) != len(mp):
            return ""
        
        # print(ans)
        return ans
        