class Solution {
public:
    // bool ispalindrome(string s){
    //     string p = "";
    //      p = s;

    //     s =reverse(p.begin() , p.end());

    //     if(p == s)
    //     return true;

    //     return false;

    // }
    bool canConstruct(string s, int k) {

        unordered_map<char , int> mpp;

        for(auto it : s){
            mpp[it]++;
        }
        
        int single = 0;
        for(auto i : mpp){
            if(i.second % 2 == 1)
            single++;
        }

        if(single<=k && k <= s.size())
        return true;

        return false;
        
    }
};