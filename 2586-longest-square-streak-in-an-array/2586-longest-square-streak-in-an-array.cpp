class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i = 0; i < n; i++) {
             st.insert(nums[i]); 
             }

        int cnt = 1, maxi = -1;
        while(!st.empty()) {

            long long curr_val = *st.begin(); // 2
            st.erase(curr_val);

            while(st.find(curr_val * curr_val) != st.end()) {
                // 4
               
                st.erase(curr_val * curr_val);
                 curr_val = curr_val * curr_val;
                cnt++;
               // [ 3, 8, 9, 16, 81, 81 ^ 2 ] Cnt++; // 2
                maxi = max(cnt, maxi);             // 3
            }
            cnt = 1;
            //[ 3, 8, 9, 81, 81 ^ 2 ]
        }
        return maxi;
    }
};