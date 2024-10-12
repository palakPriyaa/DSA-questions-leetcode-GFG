class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0); 

        // Build the graph and indegree array
        for (auto& i : pre) {
            int a = i[0];
            int b = i[1];

            adj[b].push_back(a);  
            indegree[a]++;       
        }

        queue<int> q;
        vector<int> topo;

        // Add all courses with indegree 0 to the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process courses in topological order
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If all courses are processed, return the order; otherwise, return an empty list
        if (topo.size() == n) {
            return topo;
        } else {
            return {};
        }
    }
};
