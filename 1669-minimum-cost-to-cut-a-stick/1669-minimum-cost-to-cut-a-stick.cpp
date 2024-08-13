class Solution {
public:

    int solve(int i , int j , int n, vector<int>& cuts , vector<vector<int>> &dp){
        if(i>j)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];
        
        int mini = INT_MAX;
        int cost =0;
        for(int ind = i ; ind<=j;ind++){
          cost = (cuts[j+1] - cuts[i-1]) + solve(i , ind-1 ,n, cuts , dp) + solve(ind+1 , j , n,cuts , dp);
          mini = min(cost , mini); 
        }

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();

        //adding 0 in start and n at last of cuts and sorting it for independent 
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(size+1 , vector<int>(size+1 , -1));

        return solve(1 , size , n ,  cuts , dp);


    }
};