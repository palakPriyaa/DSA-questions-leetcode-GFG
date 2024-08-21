class Solution {
public:
    int dp[101][101];
    int solve(string &s, int i, int j){
        if(i > j)
            return 0;
        if(dp[i][j] != -1) 
            return dp[i][j];

        int x = i;
        while(x + 1 <= j && s[x] == s[x + 1]) 
            x++;   

        int ans = 1 + solve(s,x + 1, j);   
        for(int k = x + 1; k <= j; k++){
            if(s[k] == s[i]){
                ans = min(ans, solve(s,k,j) + solve(s,x + 1, k - 1));  
            }
        }
        return dp[i][j] = ans;
    }
    
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size() - 1);
    }
};