class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

       if(n % 2 != 0)
       return false;

       int o = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || locked[i] == '0') {
                o++;
            } else { 
                o--;
            }
            
            if(o < 0)
            return false;
        }
        int c = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || locked[i] == '0') {
                c++;
            } else { 
                c--;
            }


            if(c < 0)
            return false;
            
        }


        return true;

       

    }
};



































