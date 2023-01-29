class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<t.size();i++){
           adj[t[i][0]].push_back({t[i][1],t[i][2]});
        }
        for(int i=0;i<adj.size();i++){
            cout<<i<<"->";
           for(int j=0;j<adj[i].size();j++){
               cout<<adj[i][j].first<<"-"<<adj[i][j].second<<" ";
           }
           cout<<endl;
        }
        vector<int> dist(n+1, 1e9);
        dist[0]=0;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int ti=x.first;
            int node=x.second;
            cout<<node<<" "<<ti<<" ";
            
            // for(auto it:adj[node]){
            //     // int y=it.first;
            //     // int dis=it.second;
            //     // if(dis+ti<dist[y]){
            //     //     dist[y]=dis+ti;
            //     //     pq.push({dist[y],y});
            //     // }
            // }
            for(auto it:adj[node]){
               int adjNode = it.first;
                int wt = it.second;
                int curr = wt + ti;
                if(curr<dist[adjNode])  {
                    dist[adjNode] = curr;
                    pq.push({curr,adjNode});
                }
            }
        }
        // return -1;
        if(*max_element(dist.begin(),dist.end())!=1e9)
            return *max_element(dist.begin(),dist.end());
        else
        return -1;
    }
};   
