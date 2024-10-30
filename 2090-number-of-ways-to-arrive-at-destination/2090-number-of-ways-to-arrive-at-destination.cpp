class Solution {
public:
    int countPaths(int n, vector<vector<int>>& grid) {
        vector<vector<pair<int, int>>> adj(n);

        // Populate adjacency list with weights
        for (auto &i : grid) {
            int src = i[0];
            int dest = i[1];
            int time = i[2];
            adj[src].push_back({dest, time});
            adj[dest].push_back({src, time});
        }

        // Min-heap priority queue with distances as long long
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        pq.push({0, 0}); // {distance, node}
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int)(1e9 + 7);

        while (!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Traverse neighbors
            for (auto &[adjnode, time] : adj[node]) {
                long long newDist = d + time;

                // First time finding the shortest path
                if (newDist < dist[adjnode]) {
                    dist[adjnode] = newDist;
                    pq.push({dist[adjnode], adjnode});
                    ways[adjnode] = ways[node];
                }
                // If we encounter the same shortest path distance
                else if (newDist == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        // Return the number of ways to reach the last node modulo 10^9+7
        return ways[n - 1] % mod;
    }
};
