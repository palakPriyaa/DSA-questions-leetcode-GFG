class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
       
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }
        
        if (n == 1 && grid[0][0] == 0) {
            return 1;
        }

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;  // distance, (row, col)

        q.push({1, {0, 0}});
        dist[0][0] = 1;

        int drow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dcol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {
            int current_dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for (int i = 0; i < 8; i++) {  // Iterate over 8 directions
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && grid[nrow][ncol] == 0 && current_dist + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = current_dist + 1;

                    if (nrow == n - 1 && ncol == n - 1)
                        return current_dist + 1;

                    q.push({current_dist + 1, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};
