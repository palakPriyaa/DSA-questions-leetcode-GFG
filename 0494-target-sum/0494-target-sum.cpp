class Solution {
public:
    int solve(vector<int>& nums, int target, vector<vector<int>> &dp, int i) {
        if (i == 0) {
            if (target == 0 && nums[0] == 0)
                return 2; // two ways: +0 and -0
            if (target == 0 || nums[0] == target)
                return 1;
            return 0;
        }

        if (target < 0) 
            return 0;

        if (dp[i][target] != -1)
            return dp[i][target];

        int nottake = solve(nums, target, dp, i - 1);
        int take = 0;
        
        if (nums[i] <= target)
            take = solve(nums, target - nums[i], dp, i - 1);

        dp[i][target] = take + nottake;
        return dp[i][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum - target < 0 || (sum - target) % 2 == 1)
            return 0;

        int s2 = (sum - target) / 2;
        
        vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
        return solve(nums, s2, dp, n - 1);
    }
};
