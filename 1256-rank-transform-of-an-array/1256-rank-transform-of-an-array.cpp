class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;  
        sort(ans.begin(), ans.end());  

        unordered_map<int, int>mpp;  
        int rank = 1;

       
        for (int num : ans) {
            if (mpp.find(num) == mpp.end()) {
               mpp[num] = rank++;
            }
        }

       
        vector<int> result;
        for (int num : arr) {
            result.push_back(mpp[num]);
        }

        return result;
    }
};
