class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);

        for(auto i : pre){
            int a = i[0];
            int b = i[1];
            adj[b].push_back(a);
        }

        vector<int> indegree(n , 0);

        for(int i =0;i<n;i++){
            for(auto it : adj[i])
            indegree[it]++;
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



        if(topo.size() == n)
        return true;

        return false;

      
       
    }
};
