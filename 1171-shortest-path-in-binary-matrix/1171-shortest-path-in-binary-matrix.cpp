class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        
        // Edge Case: If the source or destination is blocked (has a 1), return -1.
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }

        // Edge Case: If the source is already the destination and it's 0.
        if (n == 1 && grid[0][0] == 0) {
            return 1;
        }

        // Create a queue for storing cells with their distances from source
        // in the form {dist, {cell coordinates pair}}.
        queue<pair<int, pair<int, int>>> q;
        
        // Create a distance matrix with initially all the cells marked as
        // unvisited and the source cell as 1 (as we are starting from here).
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        q.push({1, {0, 0}});

        // The following delta rows and delta columns array are created such that
        // each index represents each adjacent node that a cell may have
        // in a direction (8 directions now).
        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        // Iterate through the grid by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Through this loop, we check the 8 direction adjacent nodes
            // for a shorter path to destination.
            for (int i = 0; i < 8; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Checking the validity of the cell and updating if dist is shorter.
                if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0 && dis + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = dis + 1;

                    // Return the distance if we encounter the destination cell.
                    if (newr == n - 1 && newc == n - 1)
                        return dis + 1;

                    q.push({dis + 1, {newr, newc}});
                }
            }
        }

        // If no path is found from source to destination.
        return -1;
    }
};
