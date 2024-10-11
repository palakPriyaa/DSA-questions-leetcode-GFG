class Solution {
public:

void dfs(vector<vector<char>>& grid , int row , int col){
    int rows = grid.size();
    int cols = grid[0].size();

     if(row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] != '1')
                return;


            grid[row][col] = '0';

            dfs(grid ,row - 1, col);
            dfs(grid,row + 1, col);
            dfs(grid,row, col - 1);
            dfs(grid,row, col + 1);
}
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        
        
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(grid[row][col] == '1') {
                    dfs(grid ,row, col);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};