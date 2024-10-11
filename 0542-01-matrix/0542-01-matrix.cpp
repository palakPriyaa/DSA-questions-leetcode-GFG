class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size()));
        vector<vector<bool>>visited(mat.size(),vector<bool>(mat[0].size(),false));
        queue<pair<pair<int,int>,int>>q; //{{i,j},distance}
        for(int i=0; i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int a = q.front().first.first;
            int b = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[a][b]=dis;
            if(a!=0 && !visited[a-1][b]){
                visited[a-1][b]=true;
                q.push({{a-1,b},dis+1});
            }
            if(a!=mat.size()-1 && !visited[a+1][b]){
                visited[a+1][b]=true;
                q.push({{a+1,b},dis+1});
            }
            if(b!=0 && !visited[a][b-1]){
                visited[a][b-1]=true;
                q.push({{a,b-1},dis+1});
            }
            if(b!=mat[0].size()-1 && !visited[a][b+1]){
                visited[a][b+1]=true;
                q.push({{a,b+1},dis+1});
            }
        }
        return ans;
    }
};




// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//        int n = mat.size();
//        int m = mat[0].size();
       
//        queue<pair<pair<int , int> , int>> q;
//        vector<vector<int>> vis(n , vector<int> (m , 0));
//         vector<vector<int>> dist(n , vector<int> (m , 0));


//         for(int i =0;i<n;i++){
//             for(int j =0;j<m;j++){
//                 if(mat[i][j] == 0){
//                     q.push({{i, j} , 0});
//                     vis[i][j] = 1;
//                 }
//             }
//         }
       
//         int derow[] = {-1, 0 , 1 , 0};
//         int decol[] = {-1 , 0 , +1 , 0};


//         while(!q.empty()){
//             int row = q.front().first.first;
//             int col = q.front().first.second;
//             int steps = q.front().second;
//             q.pop();

//             dist[row][col] = steps;

//             for(int i =0;i<4;i++){
//                int nrow = row + derow[i];
//                int ncol = col + decol[i];

//                if(nrow >= 0 && nrow < n && ncol >=0  && ncol < m && vis[nrow][ncol] == 0){
//                 vis[nrow][ncol] = 1;
//                 q.push({{nrow , ncol} , steps+1});

//                }
//             }
//         }


//         return dist;




//     }
// };