class Solution {
public:
    // BFS approach
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, pair<int, int>>> q;  // {time, {row, col}}
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {  
                    vis[i][j] = 1;
                    q.push({0, {i, j}});  // {time, {row, col}}
                }
            }
        }
        
        int time = 0;
        int drow[] = {-1, 0, 1, 0};  
        int dcol[] = {0, 1, 0, -1}; 
        
        // BFS traversal
        while (!q.empty()) {
            int currTime = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            time = max(time, currTime);  
          
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;  
                    q.push({currTime + 1, {nrow, ncol}}); 
                }
            }
        }
        
     
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {  
                    return -1;  
                }
            }
        }
        
        return time;  
    }
};