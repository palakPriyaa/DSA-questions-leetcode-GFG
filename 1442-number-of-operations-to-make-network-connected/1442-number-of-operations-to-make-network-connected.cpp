class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1; 

    
        class DisjointSet {
            vector<int> parent, rank;

        public:
            DisjointSet(int n) {
                parent.resize(n);
                rank.resize(n, 0);
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }

            int ultimateparent(int node) {
                if (node == parent[node]) 
                    return node;
                return parent[node] = ultimateparent(parent[node]); // Path compression
            }

            void unionbyrank(int u, int v) {
                int pu = ultimateparent(u);
                int pv = ultimateparent(v);

                if (pu != pv) {
                    // Union by rank
                    if (rank[pu] > rank[pv]) {
                        parent[pv] = pu;
                    } else if (rank[pu] < rank[pv]) {
                        parent[pu] = pv;
                    } else {
                        parent[pu] = pv;
                        rank[pv]++;
                    }
                }
            }
        };

        DisjointSet ds(n);
        for (const auto& i : connections) {
            ds.unionbyrank(i[0], i[1]);
        }

        
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.ultimateparent(i) == i) 
                components++;
        }

        // Minimum operations needed is `components - 1`
        return components - 1;
    }
};
