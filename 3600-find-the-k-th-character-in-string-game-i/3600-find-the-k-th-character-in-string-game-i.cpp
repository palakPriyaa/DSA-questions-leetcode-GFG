class Solution {
public:
    char kthCharacter(int k) {
        vector<char> aplh = {'a','b','c','d','e','f','g','h','i','j','k',
                             'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        
        string word = "a";

       
        for (int i = 0; word.size() < k; i++) {
            string temp = "";
            for (char ch : word) {
                
                int idx = find(aplh.begin(), aplh.end(), ch) - aplh.begin();
                temp += aplh[(idx + 1) % 26];  
            }
            word += temp;
        }

        return word[k - 1]; 
    }
};
