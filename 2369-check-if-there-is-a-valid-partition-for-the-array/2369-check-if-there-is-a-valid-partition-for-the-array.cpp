class Solution {
public:
    int n;
    vector<int> dp;
    bool f(int i, vector<int>& nums , vector<int> &dp){
        if (i<0) return 1;
        if (i==0) return 0; 
        if (dp[i]!=-1) return dp[i]==1;
        bool b0=0, b1=0, b2=0;
        if (i > 0 && nums[i] == nums[i-1]) 
            b0=f(i-2, nums , dp);
        if (i > 1 && nums[i] == nums[i-1] && nums[i-1] == nums[i-2])
            b1=f(i-3, nums , dp);
        if (i > 1 && nums[i] == nums[i-1]+1 && nums[i-1] == nums[i-2]+1)
            b2=f(i-3, nums , dp);
    
        return dp[i]=b0||b1||b2;
    }
    bool validPartition(vector<int>& nums) {
       int  n = nums.size();
        vector<int> dp(n  , -1);
        return f(n-1, nums , dp);
    }
};