class Solution {
public:
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

        // BFS
        vector<int> vis(V, 0);  

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                
                queue<int> q;
                q.push(i);
                vis[i] = 1; 

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto j : adj[node]) {
                        if (!vis[j]) {
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                }

                cnt++;  
            }
        }

        return cnt;
    }
};
