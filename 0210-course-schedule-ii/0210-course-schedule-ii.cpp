class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {

        vector<vector<int>> adj(n);
          vector<int> indegree(n , 0);

        for(auto &i : pre){
            int b = i[1];
            int a = i[0];

            adj[b].push_back(a);
            indegree[a]++;
        }
        
       

        queue<int> q;

        for(int i =0;i<n;i++){
            if(indegree[i] == 0)
            q.push(i);
        }

         vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto i : adj[node]){
                indegree[i]--;


                if(indegree[i] == 0)
                q.push(i);
            }

        }
     

     if(topo.size() == n)
     return topo;

     return {};

    }
};
