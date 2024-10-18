class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>&pre) {
        int n = pre.size();

         vector<vector<int>> adj(n);
         
           for(int i =0;i<n;i++){
            for(auto it : pre[i]){
            adj[it].push_back(i);
            
            }
            
        }

        vector<int> indegree(n , 0);

        for(int i =0;i<n;i++){
            for(auto it : adj[i]){
           
             indegree[it]++;
            }
            
        }

        queue<int> q;
        vector<int> topo;

        for(int i =0;i<n;i++){
            if(indegree[i] ==0 )
            q.push(i);
        }


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


sort(topo.begin() , topo.end());
return topo;
    }
};