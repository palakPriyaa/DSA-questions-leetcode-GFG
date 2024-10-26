class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
         
         int ans =0;
         sort(g.begin() , g.end());
         sort(s.begin() , s.end());

         int st= 0 , e = 0;

         while(st < m && e < n){
            if(s[e] >= g[st]){
                st++;
                e++;
                ans++;

            }
            e++;

         }

         return ans;

    }
};