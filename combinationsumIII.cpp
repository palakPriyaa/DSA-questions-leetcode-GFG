class Solution {
public:
    void solve(int d,int k,int sum,vector<vector<int>>&ans,vector<int>&v){
        
        if(k == 0){
            if(sum == 0){
                ans.push_back(v);
            }
            return;
        }
        for(int i = d; i<10; i++){
            if(i > d && i == d || d > sum){
                return;
            } 
            v.push_back(i);
            solve(i+1,k-1,sum-i,ans,v);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(1,k,n,ans,v);
        return ans;
    }
};