class Solution {
public:
    int solve(vector<vector<int>>& mat, vector<vector<int>>& dp, int i, int j, int m, int n) {
        if (i >= m || j >= n || mat[i][j] == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = solve(mat, dp, i + 1, j, m, n);
        int right = solve(mat, dp, i, j + 1, m, n);
        int dia = solve(mat, dp, i + 1, j + 1, m, n);

        dp[i][j] = 1 + min(down, min(right, dia));
        return dp[i][j];
    }

    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    cnt += solve(mat, dp, i, j, m, n);
                }
            }
        }

        return cnt;
    }
};
