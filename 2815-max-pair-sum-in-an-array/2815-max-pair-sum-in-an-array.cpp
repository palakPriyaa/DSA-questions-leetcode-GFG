class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = -1;
        
        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            char maxi = *max_element(s.begin(), s.end());
            
            for (int j = i + 1; j < n; j++) {
                string m = to_string(nums[j]);
                char maxii = *max_element(m.begin(), m.end());

                if (maxii == maxi) {
                    int sum = nums[i] + nums[j];
                    maxSum = max(maxSum, sum);
                }
            }
        }
        
        return maxSum;
    }
};
