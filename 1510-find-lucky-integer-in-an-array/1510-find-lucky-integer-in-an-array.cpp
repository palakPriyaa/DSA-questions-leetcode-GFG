class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int , int> mpp;
        for(int i : arr){
            mpp[i]++;
        }
        int maxi = -1 , ans = 0;

        for(auto &i : mpp){
            if(i.first == i.second){
               ans = i.first;
               maxi = max(maxi , ans);
            }
        }
        return maxi;
    }
};