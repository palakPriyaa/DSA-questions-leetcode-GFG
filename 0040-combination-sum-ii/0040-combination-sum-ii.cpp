
class Solution {
public:
    void solve(vector<int>& c, int target, int ind, vector<vector<int>>& ans, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = ind; i < c.size(); i++) {
            // Skip duplicates
            if (i > ind && c[i] == c[i - 1]) continue;

            
            if (c[i] > target) break;

            temp.push_back(c[i]);
            solve(c, target - c[i], i + 1, ans, temp); 
            temp.pop_back(); // Backtrack
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& c, int target) {
        sort(c.begin(), c.end()); 
        vector<std::vector<int>> ans;
        vector<int> temp;
        solve(c, target, 0, ans, temp);
        return ans;
    }
};
