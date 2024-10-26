 class Solution {
public:
    int help(vector<int>& coins, int amount, int i,vector<vector<int>>&dp)
    {
        if(amount == 0)
        return 0;

        if(i < 0 || amount < 0)
        return INT_MAX-1;
       
        if(dp[i][amount] != -1)
        return dp[i][amount];

        int take = INT_MAX;

        if(coins[i] <= amount)
        take = 1+ help(coins , amount-coins[i] , i , dp);


        int nottake = 0+ help(coins , amount , i-1 , dp);

        return dp[i][amount] = min(take,nottake);



    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n+1 , vector<int>(amount+1 , -1));

        int ans = help(coins,amount,n-1,dp);
        return (ans < INT_MAX-1)?ans:-1;

    }
};
