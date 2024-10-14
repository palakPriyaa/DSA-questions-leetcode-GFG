
class Solution { 
public:
   
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
    vector<vector<pair<int, int>>> adj(n); // {destination, price}
    
    for (const auto& flight : flights) {
        int from = flight[0], to = flight[1], price = flight[2];
        adj[from].push_back({to, price});
    }
    
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    
    
    vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
    
    
    pq.push({0, src, 0});
    dist[src][0] = 0;
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        
        int cost = curr[0];  
        int city = curr[1];  
        int stops = curr[2]; 
        
        if (city == dst) {
            return cost;
        }
        
        
        if (stops > k) {
            continue;
        }
        
        
        for (auto& neighbor : adj[city]) {
            int nextCity = neighbor.first;
            int price = neighbor.second;
            
           
            if (cost + price < dist[nextCity][stops + 1]) {
                dist[nextCity][stops + 1] = cost + price;
                pq.push({cost + price, nextCity, stops + 1});
            }
        }
    }
    

    return -1;
}


};   