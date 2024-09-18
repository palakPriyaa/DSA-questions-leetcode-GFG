class Solution {
public:

  static  bool ans(string &a , string &b){
        return a+b>b+a;}    
    string largestNumber(vector<int>& nums) {
       vector<string> v;
       bool flag =0;

       for(int i =0;i<nums.size();i++){
           if(nums[i] != 0)
              flag =1;
              v.push_back(to_string(nums[i]));
           
       } 

       if(flag == 0)
       return "0";

       sort(v.begin() , v.end() , ans);

       string solve = "";

       for(int i=0;i<v.size();i++){
           solve+= v[i];
       }
       return solve;
    }
};