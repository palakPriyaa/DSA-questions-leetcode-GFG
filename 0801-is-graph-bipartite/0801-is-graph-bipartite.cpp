//dfs

class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph, int col) {
        vis[node] = col; 

        for (auto i : graph[node]) {
            if (vis[i] == -1) {  
                if (!dfs(i, vis, graph, !col)) 
                    return false;
            } else if (vis[i] == col) {  
                return false;  
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, -1);  

        
        for (int i = 0; i < V; i++) {
            if (vis[i] == -1) {  
                if (!dfs(i, vis, graph, 0))  
                    return false;  
            }
        }

        return true;  
    }
};

//bfs

// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int V = graph.size();
//         vector<int> vis(V, -1); 

        
//         for (int start = 0; start < V; start++) {
//             if (vis[start] == -1) {  
//                 queue<int> q;
//                 q.push(start);
//                 vis[start] = 0;  // Start with color 0

//                 // Perform BFS
//                 while (!q.empty()) {
//                     int node = q.front();
//                     q.pop();

//                     // Traverse all adjacent nodes
//                     for (auto neighbor : graph[node]) {
//                         if (vis[neighbor] == -1) {  // If neighbor is unvisited
//                             vis[neighbor] = !vis[node];  // Assign opposite color
//                             q.push(neighbor);
//                         } 
//                         else if (vis[neighbor] == vis[node]) {  // Same color detected
//                             return false;  // Not bipartite
//                         }
//                     }
//                 }
//             }
//         }

//         return true;  // If no conflicts, it's bipartite
//     }
// };



// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int V = graph.size();
//         queue<int> q;
//         q.push(0);

//         vector<int> vis(V, -1);
//         vis[0] = 0;

//         while(!q.empty()){
//             int node = q.front();
//             q.pop();

//             for(auto i : graph[node]){
//                 if(vis[i] == -1){
//                     vis[i] = !vis[node];
//                     q.push(i);
//                 }

//                 else if(vis[i] == vis[node]) {
//                      return false;
//                 }
//             }
//         }

//         return true;
//     }
// };