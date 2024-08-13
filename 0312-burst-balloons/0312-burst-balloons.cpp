class Solution {
public:
    int solve(vector<int>& nums , vector<vector<int>> &dp , int i , int j){
        if(i > j)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];
        
        int maxi = INT_MIN;
        for(int ind = i ;ind <=j ;ind++){
           int ans = (nums[i-1] * nums[ind] * nums[j+1]) + solve(nums , dp , i , ind-1) + solve(nums , dp , ind+1 , j);
           maxi = max(maxi , ans);
        }

        return dp[i][j] =maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin() , 1);

        vector<vector<int>> dp(n+2 , vector<int>(n+2 , -1));
        
        return solve(nums , dp , 1 , n);
    }
};