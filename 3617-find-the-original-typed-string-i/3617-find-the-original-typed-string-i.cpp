class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int ans = 1;
        int cnt = 1;

        char ch = word[0];

        for(int i = 1; i<n;i++){
            if(word[i] == ch){
                cnt++;
            }
            else{
               ans += cnt -1;
               cnt =1;
               ch = word[i];
            }


        }

        ans += cnt -1;

        return ans;
    }
};
