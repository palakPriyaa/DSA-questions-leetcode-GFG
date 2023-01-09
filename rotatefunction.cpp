class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum =0;
        int a=0;
        for(int i=0;i<nums.size();i++){
			sum+=nums[i];
			a= a + i*nums[i];
		}
        
        int ans = a;
        
        for(int i=nums.size()-1 ;i>0; i--){
            a = a + sum - nums.size()*nums[i];
            ans = max(a,ans);
        }
        return ans;
    }
};
