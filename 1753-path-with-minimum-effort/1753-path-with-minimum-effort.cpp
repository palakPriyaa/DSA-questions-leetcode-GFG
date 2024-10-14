#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();

        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        
       
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        
        dist[0][0] = 0;
        q.push({0, {0, 0}});

        // Direction vectors for up, down, left, and right moves.
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int dis = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            
            q.pop();

            // If we've reached the bottom-right corner, return the effort.
            if (r == m - 1 && c == n - 1) {
                return dis;
            }

            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                
                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    //  new effort f
                    int newdis = max(dis, abs(h[nr][nc] - h[r][c]));

                    // If the new effort is less than the previously known effort, update it.
                    if (newdis < dist[nr][nc]) {
                        dist[nr][nc] = newdis;
                        q.push({newdis, {nr, nc}});
                    }
                }
            }
        }
       
        return 0;
    }
};
