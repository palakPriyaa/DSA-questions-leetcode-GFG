class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build the graph (adjacency list) from prerequisites
        for (auto& p : pre) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);  // Edge from prereq to course
            indegree[course]++;             // Increase indegree of course
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);  
            }
        }

        vector<int> topo;  

        // Process nodes in topological order
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // Reduce the indegree of neighboring nodes (courses dependent on this course)
            for (int nextCourse : adj[node]) {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);  // If indegree becomes 0, it can now be taken
                }
            }
        }

        // If topological sort includes all courses, return true
        return topo.size() == n;
    }
};
