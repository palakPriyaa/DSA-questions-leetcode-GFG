class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
      vector<vector<int>> adj(n);

       for(auto i : pre){
        int a = i[0];
        int b = i[1];
        
        adj[b].push_back(a);
       } 

       //indegree array
       vector<int> indegree(n ,  0);
        
        for(int i =0;i<n;i++){
          for(auto j : adj[i]){
            indegree[j]++;
        }
        }

        //push the elemts who have indegree 0 in the queue
        queue<int> q;

        for(int i =0;i<n;i++){
            if(indegree[i] == 0)
            q.push(i);
        }
       
       //topo sort array
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
       return true;

       return false;


    }
};
