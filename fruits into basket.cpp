class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i=0, j=0;
        
        
        
        int res=1;
        
        while(j<fruits.size()){
            mp[fruits[j]]+=1;
            
            if(mp.size()<2){
                res=max(res, j-i+1);
                j+=1;
            }else if(mp.size()==2){
                res=max(res, j-i+1);
                j+=1;
            }else{
                while(mp.size()>2){
                    mp[fruits[i]]-=1;
                    if(mp[fruits[i]]==0)
                        mp.erase(fruits[i]);
                    
                    i+=1;
                }
                res=max(res, j-i+1);
                
                j+=1;
            }
        }
        
        return res;
        
    }
};
