class Solution {
public:
    int dp[101][301][2];
    int solve(int i , int n , int m , vector<int>& v, int a){
        if(i>=n){
            return 0;
        }
        if(dp[i][m][a]!=-1) return dp[i][m][a];
        int ans = 0;
        int cur =0;
        
        if(a){
            for(int j = i;j<n&&j<i+2*m;j++){
                cur+=v[j];
                ans = max(ans,cur+solve(j+1,n,max(m,j-i+1),v, 1-a));
            }
        }
        
        else{
            ans = 1e6;
            for(int j = i;j<n&&j<i+2*m;j++){
                ans = min(ans,solve(j+1,n,max(m,j-i+1),v, 1-a));
            }
        }
        return dp[i][m][a]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,1,piles,1);
    }
};