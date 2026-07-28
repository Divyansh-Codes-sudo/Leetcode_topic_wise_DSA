class Solution {
public:

    bool dfs(int curr , int currcolor , vector<int> &color , vector<vector<int>> &adj){
        color[curr] = currcolor;

        for(int &v : adj[curr]){
            if (color[v] == currcolor) return false;
            
            if (color[v] == -1){
                if( !dfs(v , 1-currcolor , color , adj)) return false;
            }

        }

        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size() , -1 );
        for(int i = 0 ; i < graph.size() ; i++){
            if(color[i] == -1){
                if(!dfs(i , 0 , color , graph)) return false;
            }
        }

        return true;

    }
};