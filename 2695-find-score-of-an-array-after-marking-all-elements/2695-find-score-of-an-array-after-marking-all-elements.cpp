class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();  
        vector<int> ord(n); 
        iota(ord.begin(), ord.end(), 0);  

       
        sort(ord.begin(), ord.end(), [&](int a, int b) {
            if (nums[a] != nums[b])
                return nums[a] < nums[b];  
            return a < b;  
        });

        vector<bool> m(n, false);  
        long long score = 0;  

    
        for (int x : ord) {
            if (m[x]) 
                continue;

            score += nums[x];  
            m[x] = true;  

            
            if (x > 0)
                m[x - 1] = true;

           
            if (x + 1 < n)
                m[x + 1] = true;
        }

        return score;  
    }
};