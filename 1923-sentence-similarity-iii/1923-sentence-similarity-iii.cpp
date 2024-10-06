// Non-overlapping Approach
class Solution {
private:
    vector<string> extract_words(string sentence){
        sentence += " ";
        vector<string> ans;

        string word = "";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                ans.push_back(word);
                word="";
            }
            else{
                word += sentence[i];
            }
        }

        return ans;
    }
public:
    bool areSentencesSimilar(string x, string y) {
        
        if (x.length() < y.length()) {
            swap(x, y);
        }

        
        vector<string> vx, vy;
        vx = extract_words(x);
        vy = extract_words(y);

        int l = 0;
       
        while (l < vy.size() && l < vx.size() && vx[l] == vy[l]) {
            l++;
        }

        int r = 0;
      
        while (r < vy.size() && r < vx.size() && vx[vx.size() - 1 - r] == vy[vy.size() - 1 - r]) {
            r++;
        }

     
        return l + r >= vy.size();
    }
};