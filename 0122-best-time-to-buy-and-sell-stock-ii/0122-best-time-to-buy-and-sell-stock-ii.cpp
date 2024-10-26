class Solution {
public:
    int solve(vector<int>& p , long i , vector<vector<long>> &dp , bool buy ){
      if(i == p.size())
      return 0;

      if(dp[i][buy] != -1)
      return dp[i][buy];
      int select = 0 , notselect = 0;
      if(buy == 1){
         select = -p[i] + solve(p , i+1 , dp , 0);
        notselect = 0 + solve(p ,  i+1 , dp, 1);

        
      }

      else{
         select = p[i] + solve(p , i+1 ,dp , 1);
         notselect = 0 + solve(p ,  i+1 , dp, 0);
   
      }
      return dp[i][buy] = max(select , notselect);
    }
    int maxProfit(vector<int>& p) {
        long n = p.size();
        vector<vector<long>> dp(n, vector<long>(2, -1));

        return solve(p , 0 , dp , 1);
    }
};