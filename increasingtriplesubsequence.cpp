class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> inc(nums.size(), 0);
        int maxi(INT_MIN), cur(0);
        bool sts = false;
        for(int i=inc.size()-1; i>=0; i--){
            maxi = max(maxi, nums[i]);
            inc[i] = maxi;
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < nums[cur]) cur = i;
           if(nums[i]> nums[cur] && i+1<nums.size() && nums[i] < inc[i+1]){
               sts = true;
               break;
           }
        }
        return sts;
    }
};  
