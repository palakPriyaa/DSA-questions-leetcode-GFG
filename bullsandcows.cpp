//solved by using maps

class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int>map;
        int cow=0, bull=0;
        for(int i=0; i<secret.size(); i++){
            map[secret[i]]++;
        }
        for(int i=0; i<guess.size(); i++){
            if(secret[i]==guess[i]){
                bull++;
                
                map[guess[i]]--;
                if( map[guess[i]]==0){
                    map.erase(guess[i]);
                }
            }
            else{continue;}
        }
        for(int i=0; i<guess.size(); i++){
            if(secret[i]!=guess[i]){
                if(map.find(guess[i])!=map.end()){
                    cow++;
                    map[guess[i]]--;
                    if( map[guess[i]]==0){
                        map.erase(guess[i]);
                    }
                }
            }
            else{continue;}
        }
        string ans="";
        ans+=to_string(bull);
        ans+='A';
        ans+=to_string(cow);
        ans+='B';
        return ans;
    }
};