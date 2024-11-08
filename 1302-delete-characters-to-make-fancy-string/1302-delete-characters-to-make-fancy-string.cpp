class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();

        string a = "";
        int cnt = 1;

        for(int i =0;i<n;i++){
          if(s[i] == s[i+1]){
            cnt++;
          

          if(cnt < 3)
          a.push_back(s[i]);
          
          }
          
          else{
          a.push_back(s[i]);
          cnt = 1;
          }
        }

        return a;
    }
};