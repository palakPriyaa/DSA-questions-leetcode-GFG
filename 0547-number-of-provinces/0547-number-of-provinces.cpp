class Solution {
public:
    void dfs(vector<vector<int>>& isConnected ,  vector<vector<int>> &adj , vector<int> &vis , int node){
      
      vis[node] = 1;

      for(auto i : adj[node]){
        if(!vis[i] )
        dfs(isConnected , adj , vis , i);
      }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        // Create an adjacency list
        vector<vector<int>> adj(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;  

        // DFS
        vector<int> vis(V, 0);  

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {

                dfs(isConnected , adj , vis , i);
                cnt++;
                
               

                 
            }
        }

        return cnt;
    }
};
