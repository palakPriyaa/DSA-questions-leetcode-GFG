class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt1 = 0 , cnt2 =0;

        for(int i =0;i<bills.size();i++){
            if(bills[i] == 5){
              cnt1++; 
            }

            else if(bills[i] == 10){
                if(cnt1 > 0){
                 cnt2++;
              cnt1--;
                }
                else
                return false;
              
            }
            else{
                  if(cnt1 > 0 && cnt2 > 0){
                    cnt1--;
                    cnt2--;
                  }
                  else if(cnt1 > 2){
                    cnt1 = cnt1 -3;
                  }
                  else
                  return false;
            }
        }
        return true;
    }
};