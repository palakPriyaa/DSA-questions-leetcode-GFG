class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j) {
  
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || vis[i][j] == 1)
            return;
        
        
        vis[i][j] = 1;
        
        
        dfs(grid, vis, i+1, j);  // Down
        dfs(grid, vis, i-1, j);  // Up
        dfs(grid, vis, i, j+1);  // Right
        dfs(grid, vis, i, j-1);  // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));  
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid, vis, i, j);  
                    ans++;  
                }
            }
        }

        return ans;
    }
};
