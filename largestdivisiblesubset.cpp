class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        
        //sorting
        
        sort(nums.begin(), nums.end());
        
       //dp
        
        vector<int> dp(n, 1);
        
        
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        
        // find the maximum legth from dp table
        
        int maxi = *max_element(dp.begin(), dp.end());
        
        // find the index of maximum length
        
        int max_idx = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(dp[i] == maxi)
            {
                max_idx = i;
                
                break;
            }
        }
        
        // start taking the element from max_index
        
        vector<int> v;
        
        int i = max_idx;
        
        v.push_back(nums[i]);
        
        int p = nums[i];
        
        maxi--;
        
        i--;
        
        while(i >= 0 && maxi)
        {
            if(dp[i] == maxi && p % nums[i] == 0)
            {
                v.push_back(nums[i]);
                
                p = nums[i];
                
                maxi--;
            }
            
            i--;
        }
        
        return v;
    }
};
