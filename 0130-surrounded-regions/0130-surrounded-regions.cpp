class Solution {
public:

    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j) {
        int n = board.size();
        int m = board[0].size();
        
        
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == 'X' || vis[i][j] == 1) {
            return;
        }

        // Mark the cell as visited
        vis[i][j] = 1;

        // DFS in 4 directions
        dfs(board, vis, i + 1, j);
        dfs(board, vis, i - 1, j);
        dfs(board, vis, i, j + 1);
        dfs(board, vis, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        if (n == 0 || m == 0) return;

        vector<vector<int>> vis(n, vector<int>(m, 0));

       
        for (int i = 0; i < n; i++) {
            // First and last column
            if (board[i][0] == 'O' && vis[i][0] == 0) {
                dfs(board, vis, i, 0);
            }
            if (board[i][m - 1] == 'O' && vis[i][m - 1] == 0) {
                dfs(board, vis, i, m - 1);
            }
        }

        for (int j = 0; j < m; j++) {
            // First and last row
            if (board[0][j] == 'O' && vis[0][j] == 0) {
                dfs(board, vis, 0, j);
            }
            if (board[n - 1][j] == 'O' && vis[n - 1][j] == 0) {
                dfs(board, vis, n - 1, j);
            }
        }

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
