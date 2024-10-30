class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {0, 0}});
        dist[0][0] = 0;

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int dis = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            // If we reach the target cell with minimum effort, return it
            if (row == n - 1 && col == m - 1)
                return dis;

            for (int i = 0; i < 4; i++) {
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    int newdis = max(dis, abs(h[row][col] - h[nrow][ncol]));

                    if (newdis < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newdis;
                        q.push({newdis, {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};
